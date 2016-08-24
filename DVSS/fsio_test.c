#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// stream storage manager
struct sstorage {
    int fd;
    char* fname;
};

void usage(const char* fname) {
    printf("[usage] %s <streamNums> <buf_bits>\n", fname);
}


int main(int argc, char* argv[]) {
    if (argc < 3) {
        usage(argv[0]);
        return 0;
    }
    int streamNums;
    streamNums = atoi(argv[1]);
    if (streamNums <= 0 || streamNums > 1000) {
        printf("Invaid streamNums argument!\n");
        return 0;
    }

    struct sstorage *sstable;
    sstable = (struct sstorage*)malloc(streamNums * sizeof(struct sstorage));
    if (sstable == NULL) {
        perror("Malloc memory for sstable failed");
        return 0;
    }

    time_t rawtime;
    struct tm *timeinfo;
    char datestr[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(datestr, 80, "%F-%H%M%S", timeinfo);



    for (int i = 0; i < streamNums; i++) {
        char fname[80];
        sprintf(fname, "SID%04d-%s", i, datestr);
        sstable[i].fname = strdup(fname);

        umask(0);
        if ((sstable[i].fd = open(fname, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0664)) == -1) {
            perror("Open file failed");
            return 0;
        }
    }

    // concurrent stream write
    int buf_bits;
    buf_bits = atoi(argv[2]);
    long long bytesWrite = 0;
    int bufsize = 1 << buf_bits;  
    int file_size = 32 * 1024 * 1024;
    int loops = file_size / bufsize;
    struct timeval t1, t2;
    double elapsedTime;
    printf("buf size = %f KB\t file_size= %f MB\n", bufsize * 1.0 / 1024, file_size * 1.0 / (1024*1024));

    char *gop = (char*)malloc(sizeof(char) * bufsize);
    if (gop == NULL)
    {
        perror("Malloc memory for gop failed");
        return 0;
    }
    memset(gop, 0x43, bufsize);

    gettimeofday(&t1, NULL);
    for (int i = 0; i < loops; i++) {

        for (int j = 0; j < streamNums; j++) {
            int nwrite = write(sstable[j].fd, gop, bufsize);
            bytesWrite += nwrite;
        }
    }

    for (int i = 0; i < streamNums; i++) {
         fsync(sstable[i].fd);
    }

    gettimeofday(&t2, NULL);

    elapsedTime = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec) / 1000000.0;

    double writeSpeed = bytesWrite / elapsedTime;

    printf("Data write in Bytes: %lld (%f in MB)\n", bytesWrite, (double)bytesWrite/(1024*1024));
    printf("Time duration: %f (sec)\n", elapsedTime);
    printf("writespeed: %f (B/s)  (%f MB/s)\n", writeSpeed, writeSpeed/(1024*1024));


    for (int i = 0; i < streamNums; i++) {
         close(sstable[i].fd);
         free(sstable[i].fname);
    }
    free(sstable);
    return 0;
}
