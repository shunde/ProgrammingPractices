#ifndef _BUDDY_H
#define _BUDDY_H

struct buddy;

struct buddy* buddy_create(int n);
int buddy_alloc(struct buddy* self, int n);
int buddy_free(struct buddy* self, int offset);
void buddy_destory(struct buddy* self);
void buddy_dump(struct buddy* self);

#endif