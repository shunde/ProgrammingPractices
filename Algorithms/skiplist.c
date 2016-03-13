#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



#define MAX_LEVEL 16 
#define BRANCH 4


typedef struct skiplistNode {
	int value; 
	struct skiplistNode *backward;
	struct skiplistLevel {
		struct skiplistNode *forward;
		int span;
	} level[];
} skiplistNode;

typedef struct skiplist {
	int length;
	int high;
	skiplistNode *head, *tail;
} skiplist;

void err_exit(const char* msg) {
	printf(stderr, "Error: %s\n", msg);
	exit(0);
}

skiplistNode* createNode(int level, int value) {
	skiplistNode* sn = (skiplistNode*)malloc(sizeof(*sn) + level * sizeof(struct skiplistLevel))
	if (!sn) err_exit("malloc skiplistNode failed!");
	sn->value = value;
	sn->backward = NULL;
	for (int i = 0; i < level; i++) {
		sn->level[i].forward = NULL;
		sn->level[i].span = 0;
	}
	return sn;
}

skiplist* createSkiplist() {
	skiplist *sl = (skiplist*)malloc(sizeof(skiplist));
	if (!sl) err_exit("malloc skiplist failed!");

	sl->head = createNode(MAX_LEVEL, INT_MIN);
	sl->tail = null;
	sl->length = 0;
	sl->high = 1;
	return sl;
}

int randLevel() {
	int level = 1;
	while (level < MAX_LEVEL && (rand() % BRANCH) == 0) 
		level++;
	return level;
}


skiplist* insertSkiplist(skiplist *sl, int value) {
	skiplistNode *update[MAX_LEVEL], *next;
	int level = randLevel();
	skiplistNode *newNode = createNode(level, value);

	// todo:

	return sl;
}