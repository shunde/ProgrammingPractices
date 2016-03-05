#include <sys/select.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    printf("FD_SETSIZE=%d\n", FD_SETSIZE);
    return 0;
}
