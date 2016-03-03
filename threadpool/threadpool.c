#include <stdlib.h>
#include <stdio.h>
#include "threadpool.h"


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


static void *thread_model(void *arg);
static job_queue_t* job_queue_create(int maxJobSize);
static int job_queue_destory(job_queue_t *jobq);
static void err_exit(char *msg);



// 线程模型
static void *thread_model(void *arg) {
    threadpool_t *tp = (threadpool_t *)arg;
    job_queue_t *jobq = tp->jobq;

    job_t *job;

    while(true) {
        // check threadpool status
        // peak a task
        // execute a task
        if (tp->stop)
            break;

        pthread_mutex_lock(&jobq->lock);
        while (jobq->n == 0)
            pthread_cond_wait(&jobq->ready, &jobq->lock);
        
        job = jobq->head;
        jobq->head = job->next;
        jobq->n--;
        if (jobq->n == 0)
            jobq->tail == NULL;
        pthread_mutex_unlock(&jobq->lock);

        pthread_mutex_lock(&tp->plock);
        tp->idlNum--;
        tp->busyNum++;
        pthread_mutex_unlock(&tp->plock);

        job->task(job->arg);

        pthread_mutex_lock(&tp->plock);
        tp->idlNum++;
        tp->busyNum--;
        pthread_mutex_unlock(&tp->plock);
        
        pthread_cond_signal(&tp->done);
    }
    //pthread_exit((void *)0);
    return (void *)0;
}

static void err_exit(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(0);
}


static job_queue_t* job_queue_create(int maxJobSize) {
    job_queue_t *jobq = (job_queue_t *)malloc(sizeof(job_queue_t));
    if (jobq == NULL)
        err_exit("create job_queue failed due to out of memory!");
    jobq->maxJobSize = maxJobSize;
    jobq->n = 0;
    jobq->head = jobq->tail = NULL;

    if (pthread_mutex_init(&jobq->lock, NULL) != 0) 
        err_exit("init pthread_mutex_t failed!");

    if (pthread_cond_init(&jobq->ready, NULL) != 0)
        err_exit("init pthread_cond_t failed!");

    return jobq;
}

static int job_queue_destory(job_queue_t *jobq) {
    if (tp == NULL) return 0;

    pthread_mutex_lock(&jobq->lock);
    job_t *job = jobq->head;
    while (job != NULL) {
        jobq->head = job->next;
        free(job);
        job = jobq->head;
    }
    jobq->head = jobq->tail = NULL;
    jobq->n = 0;
    pthread_mutex_unlock(&jobq->lock);

    pthread_mutex_destory(&jobq->lock);
    pthread_cond_destory(&jobq->ready);
    return 0;
}

int threadpool_init(threadpool_t *tp, int corePoolSize, int maxPoolSize, int maxJobSize) {
    if (tp == NULL) return 0;

    tp->corePoolSize = corePoolSize;
    tp->maxPoolSize = maxPoolSize;
    tp->n = 0;
    tp->jobq = job_queue_create(maxJobSize);
    tp->ready = 0;
    tp->stop = false;

    if (pthread_mutex_init(tp->plock, NULL) != 0)
        err_exit("init mutex failed in threadpool!");

    if (pthread_cond_t(tp->done, NULL) != 0)
        err_exit("init pthread_cond_t failed in threadpool!");

    tp->threads = (pthread_t *)malloc(sizeof(pthread_t) * maxPoolSize);
    if (tp->threads == NULL) 
        err_exit("alloc threads space failed!");

    int count = 0;
    for (; count < corePoolSize; count++) {
        if (pthread_create(&tp->threads[count], NULL, thread_model, (void *)tp) != 0) {
            err_exit("create thread failed!");
        }
    }
    tp->n = count;
    tp->idlNum = count;
    tp->busyNum = 0;
    //tp->ready = 1;
    //pthread_cond_broadcast(&tp->done);
    return 0; // succeed
}

int threadpool_add_task(threadpool_t *tp, taskfn_t task, void *arg) {
    if (tp == NULL) return 0;

    job_t *newjob = (job_t *)malloc(sizeof(job_t));
    if (newjob == NULL) {
        err_exit("create new job failed!");
    }

    newjob->task = task;
    newjob->arg = arg;
    newjob->next = NULL;

    pthread_mutex_lock(&tp->jobq->lock);
    if (tp->jobq->n == 0) {
        tp->jobq->head = tp->jobq->tail = newjob;
    } else {
        tp->jobq->tail->next = newjob;
        tp->jobq->tail = newjob;
    }
    tp->jobq->n++;
    pthread_mutex_unlock(&tp->jobq->lock);
    pthread_cond_signal(&tp->jobq->ready);
    return 0;
}

int threadpool_stop(threadpool_t *tp) {
    if (tp == NULL) return 0;
    tp->stop = true;
}

void threadpool_debug(threadpool_t *tp) {
    if (tp == NULL) return;

    int maxPoolSize, n, idlNum, busyNum;

    pthread_mutex_lock(&tp->plock);
    maxPoolSize = tp->maxPoolSize;
    n = tp->n;
    idlNum = tp->idlNum;
    busyNum = tp->busyNum;
    pthread_mutex_unlock(&tp->plock);

    printf("maxPoolSize=%d\tsize=%d\tidleNum=%d\tbusyNum=%d\n",
        maxPoolSize, n, idlNum, busyNum);

    return;
}

int threadpool_destory(threadpool_t *tp) {
    if (tp == NULL) return 0;

    job_queue_destory(tp->jobq);

    // cancle every thread
    for (int i = 0; i < tp->n; i++) {
        pthread_cancel(tp->threads[i]);
    } 
    pthread_mutex_destory(&tp->plock);
    pthread_cond_destory(&tp->done);

    tp->corePoolSize = 0;
    tp->maxPoolSize = 0;
    tp->n = 0;
    tp->idlNum = 0;
    tp->busyNum = 0;

    free(tp->jobq);
    free(tp->threads);

    return 0;
}

int threadpool_wait(threadpool_t *tp) {
    if (tp == NULL) return 0;

    pthread_mutex_lock(&tp->plock);
    while (tp->n != tp->idlNum) {
        pthread_cond_wait(&tp->done, &tp->plock);
    }
    pthread_mutex_unlock(&tp->plock);

    return 0;
}

