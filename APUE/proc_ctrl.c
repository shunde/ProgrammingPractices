#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    printf("pid=%d\tppid=%d\tuid=%d\teuid=%d\tgid=%d\tegid=%d\n", 
        getpid(), getppid(), getuid(), geteuid(), getgid(), getegid());
    return 0;
}