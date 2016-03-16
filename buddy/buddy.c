#include "buddy.h"
#include <stdio.h>
#include <stdlib.h>


#define IS_POWER_OF_2(n) (!((n)&((n)-1)))
#define LLEAF(n) (((n)+1)*2 - 1)
#define RLEAF(n) (((n)+1)*2)
#define PARENT(n) (((n)-1)/2)
#define MAX(a, b) ((a)>(b)?(a):(b))

static int bound_up(int n) {
	n -= 1;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n += 1;
	return n;
}


struct buddy {
	uint8_t size;
	uint8_t longest[0];
};



struct buddy* buddy_create(int n) {
	if (n < 1 || !IS_POWER_OF_2(n)) return NULL;

	struct buddy* bp = (struct buddy*)malloc(sizeof(struct buddy) + n * 2 * sizeof(uint8_t));
	if (!bp) return NULL;

	bp->size = n;
	int node_size = n * 2;

	for (int i = 0; i < 2*n; i++) {
		if (IS_POWER_OF_2(i+1))
			node_size /= 2;
		bp->longest[i] = node_size;
	}
	return bp;
}

int buddy_alloc(struct buddy* self, int n) {
	if (!self) return -1;

	if (n < 1)
		n = 1;
	else
		n = bound_up(n);

	if (self->size < n || self->longest[0] < n) return -1;

	int index = 0;
	int node_size = self->longest[0];

	for (; node_size != n; node_size /= 2) {
		if (self->longest[LLEAF(index)] >= n)
			index = LLEAF(index);
		else
			index = RLEAF(index);
	}

	self->longest[index] = 0;
	int off_set = (index + 1) * node_size - self->size;

	while (index) {
		index = PARENT(index);
		self->longest[index] = MAX(self->longest[LLEAF(index)], self->longest[RLEAF(index)]);
	}

	return off_set;
}

void buddy_free(struct buddy* self, int off_set) {
	// todo:
}

