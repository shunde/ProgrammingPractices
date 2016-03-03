#include "threadpool.h"
#include <stdio.h>
#include <unistd.h>


void* worker(void *arg) {
    pid_t pid;
    pthread_t tid;
    
    pid = getpid();
    tid = pthread_self();

    printf("Thread %lu (0x%lx) execute job %d in process %lu\n", 
            (unsigned long)tid, (unsigned long)tid, (int)arg, (unsigned long)pid);
    sleep(2);
    return (void *)0;
} 

int main(int argc, char *argv[]) {
    threadpool_t tp;
    threadpool_init(&tp, 10, 20, 20);
    for (int i = 0; i < 100; i++) {
        threadpool_add_task(&tp, worker, (void *)i);
    }

    threadpool_wait(&tp);

    printf("All done!");
    
    return 0;
}
