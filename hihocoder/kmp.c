#include <stdio.h>

void getNext(char* pattern, int *next, int n) {
    int i, j;
    next[0] = -1;
    j = -1;
    for (i = 0; i < n-1; ) {
        if (j == -1 || pattern[i] == pattern[j]) {
            ++i;
            ++j;           
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

void test_next() {
    char *pattern = "abcabca";
    int next[7];
    getNext(pattern, next, 7);
    for (int i = 0; i < 7; i++)
        printf("%d ", next[i]);
    printf("\n");
}

int main() {
    test_next();
    return 0;
}