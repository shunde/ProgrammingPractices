#include "buddy.h"
#include <stdio.h>

int main() {
    struct buddy *bp = buddy_create(32);
    buddy_dump(bp);

    int len[4] = {1, 4, 16, 8};
    int idx[4] = {0};

    for (int i = 0; i < 4; i++) {
        idx[i] = buddy_alloc(bp, len[i]);
        printf("Alloc %d (at %d)\n", len[i], idx[i]);
        buddy_dump(bp);
    }

    for (int i = 0; i < 4; i++) {
        buddy_free(bp, idx[i]);
        printf("free %d (at %d)\n", len[i], idx[i]);
        buddy_dump(bp);
    }

    return 0;
}

