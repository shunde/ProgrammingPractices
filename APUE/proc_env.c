// 进程环境

#include <stdio.h>
#include <stdlib.h>

static void my_exit1(void);
static void my_exit2(void);

void err_sys(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (atexit(my_exit2) != 0)
        err_sys("can't register my_exit2");

    if (atexit(my_exit1) != 0)
        err_sys("can't register my_exit1");
    if (atexit(my_exit1) != 0)
        err_sys("can't register my_exit1");

    for (int i = 0; argv[i] != NULL; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }

    // environ 
    for (int i = 0; environ[i] != NULL; i++) {
        printf("environ[%d]=%s\n", i, environ[i]);
    }

    return 0;
}

static void my_exit1() {
    printf("first exit handler.\n");
}

static void my_exit2() {
    printf("second exit handler\n");
}
