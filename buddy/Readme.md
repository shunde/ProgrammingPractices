读了 [伙伴分配器的一个极简实现](http://coolshell.cn/articles/10427.html) 文章后，看了下 [wuwenbin](https://github.com/wuwenbin/buddy2) 的实现，为了加强理解，又复刻了一遍。

这个伙伴分配器很容易扩展，`buddy_alloc` 返回申请内存的偏移，然后用户去大内存上索引出来就行，用完了调用 `buddy_free` 归还。
