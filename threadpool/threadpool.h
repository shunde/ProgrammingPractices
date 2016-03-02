#ifndef _THREADPOOL_H
#define _THREADPOOL_H

typedef struct threadpool threadpool_t;

struct threadpool {
	int corePoolSize;   // 线程池基本大小。
	int maxPoolSize;    // 线程池最大容量，大于这个就不会再创建线程了
	int n;              // 线程池当前线程个数。
	int idlNum;         // 空闲线程数
	int busyNum;        // 忙碌线程数
	

};

#endif // _THREADPOOL_H