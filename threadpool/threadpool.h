#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <pthread.h>

struct threadpool;
typedef struct threadpool threadpool_t;

struct job;
typedef struct job job_t;

struct job_queue;
typedef struct job_queue job_queue_t;

typedef void * (*taskfn_t)(void *);


int threadpool_init(threadpool_t *tp, int corePoolSize, int maxPoolSize, int maxJobSize);
int threadpool_add_task(threadpool_t *tp, taskfn_t task, void *arg);
int threadpool_stop(threadpool_t *tp);
int threadpool_wait(threadpool_t *tp);  // wait all jobs done
//int threadpool_restart(threadpool_t *tp);
int threadpool_destroy(threadpool_t *tp);
 

// 输出线程池状态信息
void threadpool_debug(threadpool_t *tp);

#endif // _THREADPOOL_H