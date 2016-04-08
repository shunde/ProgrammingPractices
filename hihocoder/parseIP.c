#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        unsigned int c1, c2, c3, c4, c5;
        c5 = 32;
        scanf("%d.%d.%d.%d/%d", &c1, &c2, &c3, &c4, &c5);
        printf("%d.%d.%d.%d/%d\n", c1, c2, c3, c4, c5);
    }
    return 0;
}