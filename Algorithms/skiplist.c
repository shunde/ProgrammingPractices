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
	fprintf(stderr, "Error: %s\n", msg);
	exit(0);
}

skiplistNode* createNode(int level, int value) {
	skiplistNode* sn = (skiplistNode*)malloc(sizeof(*sn) + level * sizeof(struct skiplistLevel));
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
	sl->tail = NULL;
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


	if (level > sl->high) {
		sl->high = level;
		for (int i = sl->high; i < level; i++) {
			sl->head->level[i].forward = newNode;
		}
	}


	next = sl->head;
	for (int i = sl->high - 1; i >= 0; i--) {
		while (next->level[i].forward && next->level[i].forward->value < value)
			next = next->level[i].forward;
		update[i] = next;
	}

	for (int i = level - 1; i >= 0; i--) {
		newNode->level[i].forward = update[i]->level[i].forward;
		update[i]->level[i].forward = newNode;
		
	}

	newNode->backward = (update[0] == sl->head)? NULL : update[0];
	if (!newNode->level[0].forward) sl->tail = newNode;
	else newNode->level[0].forward->backward = newNode;
	
	sl->length++;

	return sl;
}


skiplistNode* findSkiplist(skiplist *sl, int value) {
	if (!sl || !sl->head ) return NULL;
	skiplistNode *x = sl->head;
	
	for (int i = sl->high - 1; i >= 0; i--) {
		while (x->level[i].forward && x->level[i].forward->value < value)
			x = x->level[i].forward;		
	}
	x = x->level[0].forward;
	if (x && x->value == value) return x;
	else return NULL;
}

void printSkiplist(skiplist *sl) {
	if (!sl || !sl->head) return;
	printf("Summary:\n");
	printf("High: %d\nLength: %d\n", sl->high, sl->length);
	skiplistNode* sn;
	for (int i = sl->high-1; i >= 0; i--) {
		printf("Level %d: ", i);
		sn = sl->head->level[i].forward;
		while (sn) {
			printf("%d(0x%x), \t", sn->value, sn);
			sn = sn->level[i].forward;
		}
		printf("\n");
	}
}

int main(int argc, char* argv[]) {
	skiplist *sl = createSkiplist();
	int A[] = {9, 4, 3, 1, -2, 25, 32, 12, 100, 2, 7, 6, 54, 100};
	int B[] = {100, -2, 11, 25, 3, 54, 10, 6};

 	for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
		sl = insertSkiplist(sl, A[i]);
	printSkiplist(sl);
	for (int i = 0; i < sizeof(B)/sizeof(B[0]); i++) {
		skiplistNode* sn = findSkiplist(sl, B[i]);
		if (sn) printf("find %d at 0x%x(%d)\n", B[i], sn, sn->value);
		else printf("Not find %d\n", B[i]);
	}
	return 0;
}