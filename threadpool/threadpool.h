#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <pthread.h>
#include <stdbool.h>

typedef struct threadpool threadpool_t;
typedef struct job job_t;
typedef struct job_queue job_queue_t;

typedef void * (*taskfn_t)(void *);

struct threadpool {
    int corePoolSize;   // 线程池基本大小。
    int maxPoolSize;    // 线程池最大容量，大于这个就不会再创建线程了
    int n;              // 线程池当前线程个数。
    int idlNum;         // 空闲线程数
    int busyNum;        // 忙碌线程数
    job_queue_t *jobq;
    pthread_t *threads;
    pthread_mutex_t plock;
    pthread_cond_t done;    
    bool stop;         
};

struct job {
    taskfn_t task;
    void *arg;
    struct job *next;
};

struct job_queue {
    int maxJobSize;
    int n;
    pthread_mutex_t lock;
    pthread_cond_t ready; 
    job_t *head;
    job_t *tail;
};



int threadpool_init(threadpool_t *tp, int corePoolSize, int maxPoolSize, int maxJobSize);
int threadpool_add_task(threadpool_t *tp, taskfn_t task, void *arg);
int threadpool_stop(threadpool_t *tp);
int threadpool_wait(threadpool_t *tp);  // wait all jobs done
//int threadpool_restart(threadpool_t *tp);
int threadpool_destroy(threadpool_t *tp);
 

// 输出线程池状态信息
void threadpool_debug(threadpool_t *tp);

#endif // _THREADPOOL_H
