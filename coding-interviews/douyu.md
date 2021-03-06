# 斗鱼面试

> 2016.09.11

## 笔试

笔试题都很典型。

1. C++中 `static`、`const`、`volatile`、`mutable` 的作用。

2. 使用UDP如何知道数据报文已经被对方接收。

3. N个数的数组的范围是1~N，判断是否有重复数字。

4. 实现LRU。

   参照 [LRU Cache -- Leetcode](https://leetcode.com/problems/lru-cache/) 的接口规范。

   ```C++
   /**
    * 实现如下操作：get 和 set
    * get(key) - Get the value of the key if it exists in cache, otherwise return -1.
    * set(key, value) - Set or insert the value if the key is not already present.
    * when the cache reached its capacity, 
    * it should invalidate the least recently used item before inserting a new item.
    */
   Class LRUCache {
   public:
     LRUCache(int capacity) {}
     int get(int key) {} 
     void set(int key, int val) {}
   };
   ```

   ​

5. x64系统struct 结构体大小。注意**函数指针和long大小**。

6. 排序算法的稳定性。

7. fork创建子进程哪个不会被复制给子进程。



## 一面

1. redis 如何实现事务。

   参考：《Redis 设计与实现》 、[事务——Redis 设计与实现](http://redisbook.readthedocs.io/en/latest/feature/transaction.html)

   `MULTI`、`EXEC`、`DISCARD` 和 `WATCH` 是 Redis 事务的基础。

   **事务：** 将多个命令打包，然后一次性、按顺序地执行。有如下两个重要保证：

   - 事务是一个单独的隔离操作：事务中所有的命令都会序列化、按顺序地执行。事务在执行的过程中，不会被其他客户端发送来的命令请求所打断。
   - 事务是一个原子操作：事务中的命令要么全部执行，要么全部都不执行。

   **事务的三个阶段：**

   - 开始事务。由 `MULTI` 开始一个事务。
   - 命令入队。服务器维护一个事务队列，将命令放进事务队列中，并返回QUEUED字符串表示命令已经入队列。
   - 执行事务。最后由`EXEC` 命令触发事务。

   **带`WATCH` 的事务：**

   `WATCH` 用于在事务开始之前，监视任意数量的键；当调用 EXEC 命令执行事务时，如果任意一个被监视的键已被其他客户端修改，那么整个事务不再执行，直接返回失败。

   ​

   ​

   ​



## 二面

> 群面。两个面试官两个应聘者。
>
> 我和老谭对。虐心。

1. Chrome 浏览器最新版本号。

2. 在浏览器地址栏输入 “baidu.com”  到显示出页面来的整个过程。

3. 如何打印出DNS查询过程？

   DNS查询工具有：

   - `nslookup`， 已被遗弃，很少使用。
   - `dig`，灵活，功能强大。
   - `host`，功能简单。

   **跟踪 dig 全过程：**

   ```shell
   $ dig +trace roclinux.cn
   ```

   ​

   ​

   ​

4. TCP 三次握手和四次挥手的状态转换图。accept 调用是在哪个阶段？

5. 服务器出现大量的 TIME_WAIT 状态是为什么？TIME_WAIT出现在主动关闭连接的那一方还是被动关闭链接的那一方？

6. 网络编程各个系统调用的顺序。

7. HTML插入样式表有几种方法。

   答：三种方法。

   （1）外部样式表。

   ```html
   <head>
     <link ref="stylesheet" type="text/css" href="mystyle.css">
   </head>
   ```

   （2）内部样式表。

   ```html
   <head>
     <style type="text/css">
       body {background-color: red}
       p {margin-left: 20px}
     </style>
   </head>
   ```

   （3）内联样式

   ```html
   <p style="color: red; margin-left: 20px">
     This is a paragraph.
   </p>
   ```

   ​

8. STL有哪些坑。

9. `vector` 的 `reserve()` 方法和 `resize()` 方法的区别。

   答：`std::vector::reserve(size_type n)` 请求 vector 容量（capacity）至少能够包含 n 个元素。

   如果 n 大于当前 vector 的容量，此方法会导致容器重新分配存储空间使容量增加到 n （或大于 n）；

   如果 n 小于等于当前 vector 的容量，该方法的调用什么都不做。
   该方法对 vector 的 size 没有影响，也不能修改其中的元素。

   `std::vector::resize(size_type n, value_type val = value_type())` 重新调整容器大小，使之恰好包含 n 个元素。

   如果 n 小于当前容器的 size，容器的前 n 个元素会被保留，后面的元素会被移除（和销毁）。

   如果n 大于当前容器的 size，那么容器会通过在尾部插入足够的元素 val 使容器的 size 为 n。如果 指定了 val，则使用 val 初始化新插入的元素；如果没有指定，则调用默认的构造函数。

   注意：此方法通过插入或移除其中的元素，确确实实修改了容器的内容。

   参考链接：

   1. [vector.resize() 与 vector.reserve() 的区别](http://blog.csdn.net/shuilan0066/article/details/3588478)
   2. cplusplus.com [std::vector::resize](http://www.cplusplus.com/reference/vector/vector/resize/) 和 [std::vector::reserve](http://www.cplusplus.com/reference/vector/vector/reserve/)

10. `vector` 的 `at()` 和 `operator[]` 的区别。

   答：`at()` 和 `operator[]` 的作用相同。相比较 `operator[]` 而言，`at()` 会对边界范围进行检查，如果越界会抛出 `out_of_range` 异常。

11. STL 迭代器的分类。

   答：根据移动性和施行操作，分为五类：

- Input Iterator，输入迭代器


- Output Iterator，输出迭代器
- Forward Iterator，前向迭代器
- Bidirectional Iterator，双向迭代器
- Random Access Iterator，随机访问迭代器

111. Redis 各个数据结构对应的底层数据结构。

121. 从源代码到生成可执行文件，经历了哪些步骤。

   答：参考链接 [C/C++源代码到可执行程序的过程详解](http://www.jianshu.com/p/cdcaaed3a767)

   **源代码 --> 编译预处理 --> 编译 --> 优化 --> 汇编 --> 链接 --> 可执行文件**

1.    编译预处理

      读取C/C++源程序，对其中的伪指令（以#开头的指令）和特殊符号进行处理（替换）

      （1) 宏定义指令。进行宏替换。

      （2）条件编译指令。如`#ifdef` 、`#ifndef`、 `#else` 、`#endif` 等等。

      （3）头文件包含指令。

      （4）特殊符号。如 `__LINE__` 、`__FILE__` 、`__DATE__`、`__FUNCTION__`等。

2.    编译阶段

         通过词法和语法分析，将其翻译成等价的中间代码表示或汇编代码。

3.    优化阶段

      优化有两种：（1）对中间代码的优化，不依赖于具体的计算机；（2）针对对目标代码生成的优化。

      第一种优化主要的工作是删除公共表达式，循环表达式（代码外提，强度削减，变量循环控制，已知变量合并等）、复写传播、无用赋值的删除，等等。

      第二种优化同机器的硬件结构密切相关，主要考虑如何充分利用机器的各个硬件寄存器存放的有关变量的值，以减少对内存的访问次数。

      经过优化的汇编代码必须经过汇编程序转换成相应的机器指令，方可能被机器执行。

4.    汇编过程。

      将汇编语言代码翻译成目标的机器指令。

      目标文件由段组成。通常一个目标文件至少包含两个段：代码段和数据段。

      Unix环境下目标文件主要有三种类型：

      （1）可重定位文件。

      （2）共享的目标文件。

      （3）可执行文件。

      汇编程序生成的实际上是第一种类型的目标文件。

5.    链接程序

      （1）静态链接；（2）动态链接。

      ​