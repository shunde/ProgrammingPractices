#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>



int main(int argc, char* argv[]) {
    int fd = open("/dev/raw/raw1", O_RDWR);
    if (fd == -1) {
        perror("fail to open /dev/raw/raw1");
        return 0;
    }

    char* buf;
    int bs = 1024;
    int alignment = 512;

    buf = memalign(alignment, bs);
    if (buf == NULL) {
        perror("fail to memalign.");
        return 0;
    }

    memset(buf, 0x73, 512);
    memset(buf+512, 0x79, 512);

    int nwrite = 0;

    if ((nwrite = write(fd, buf, 512)) == -1) {
         perror("fail to write ss.");
         return 0;
    }

    lseek(fd, 512, SEEK_SET);

    if ((nwrite = write(fd, buf+512, 512)) == -1) {
         perror("fail to write yy.");
         return 0;
    }

    close(fd);

    return 0;

}


