#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>


void usage(const char* fname) {
    printf("[usage] %s <streamNums> \n", fname);
}

struct BLK {
    int idx;
    int off_set;
    int remain;
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        usage(argv[0]);
        return 0;
    }
    int streamNums;
    streamNums = atoi(argv[1]);
    if (streamNums <= 0 || streamNums > 1000) {
        printf("Invaid streamNums argument!\n");
        return 0;
    }


    int fd;
    if ((fd = open("/dev/raw/raw1", O_RDWR)) == -1) {
        perror("fail to open /dev/raw/raw1");
        return 0;
    }

    char* buf;
    int alignment = 512;
    int bs = 4 * 1024;

    buf = memalign(alignment, bs);
    if (buf == NULL) {
        perror("fail to memalign.");
        return 0;
    }

    memset(buf, 0x43, bs);


    // concurrent stream write
    long long bytesWrite = 0;
    int bufsize = 4 * 1024;  // 4KB
    int loops = 600;
    struct timeval t1, t2;
    double elapsedTime;

    gettimeofday(&t1, NULL);

    for (int i = 0; i < loops; i++) {

        for (int j = 0; j < streamNums; j++) {
            int nwrite = write(fd, buf, bs);
            bytesWrite += nwrite;
        }
    }


    gettimeofday(&t2, NULL);

    elapsedTime = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec) / 1000000.0;

    double writeSpeed = bytesWrite / elapsedTime;

    printf("Data write in Bytes: %lld (%f in MB)\n", bytesWrite, (double)bytesWrite/(1024*1024));
    printf("Time duration: %f (sec)\n", elapsedTime);
    printf("writespeed: %f (B/s)  (%f MB/s)\n", writeSpeed, writeSpeed/(1024*1024));


    close(fd);

    return 0;
}
