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
    printf("[usage] %s <streamNums> <bs_bit> \n", fname);
}

struct blk_info {
    int idx;
    off_t offset;
    int remain;
};

void init_blk(struct blk_info *blkptr, int idx, int offset, int remain) {
    blkptr->idx = idx;
    blkptr->offset = offset;
    blkptr->remain = remain;
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
    int bs_bits;
    bs_bits = atoi(argv[2]);


    int fd;
    if ((fd = open("/dev/raw/raw1", O_RDWR)) == -1) {
        perror("fail to open /dev/raw/raw1");
        return 0;
    }

    char* buf;
    int alignment = 4096;
    int bs = 1 << bs_bits;

    int blk_size = 600 * 1024 * 1024; // 600M;
   
    printf("bufsize = %f KB, blksize = %f MB\n", bs/1024.0, blk_size*1.0/(1024*1024));

    buf = memalign(alignment, bs);
    if (buf == NULL) {
        perror("fail to memalign.");
        return 0;
    }

    memset(buf, 0x43, bs);

    struct blk_info *blkptrs = (struct blk_info*)malloc(sizeof(struct blk_info) * streamNums);
    if (blkptrs == NULL) {
         perror("fail to malloc memory for blk_info tables");
         return 0;
    }

    int free_blk_idx = 0;
    for (int i = 0; i < streamNums; i++) {
         init_blk(&blkptrs[i], free_blk_idx, 0, blk_size);
         free_blk_idx += 1;
    }

    // concurrent stream write
    long long bytesWrite = 0;
    int loops = 32 * 1024 * 1024 / bs;
    //int loops = blk_size / bs;
    struct timeval t1, t2;
    double elapsedTime;

    gettimeofday(&t1, NULL);

    off_t offset;

    for (int i = 0; i < loops; i++) {
        for (int j = 0; j < streamNums; j++) {
            offset = (blkptrs[j].idx * blk_size) + blkptrs[j].offset;
            lseek(fd, offset, SEEK_SET);
            int nwrite = write(fd, buf, bs);
            blkptrs[j].offset += nwrite;
            // todo: 更新 remain
            bytesWrite += nwrite;
        }
    }

    gettimeofday(&t2, NULL);

    elapsedTime = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec) / 1000000.0;

    double writeSpeed = bytesWrite / elapsedTime;

    printf("#Data write in Bytes: %lld (%f in MB)\n", bytesWrite, (double)bytesWrite/(1024*1024));
    printf("#Time duration: %f (sec)\n", elapsedTime);
    printf("writespeed: %f (B/s)  (%f MB/s)\n", writeSpeed, writeSpeed/(1024*1024));


    close(fd);

    return 0;
}
