#include <stdio.h>

int main() {
    int a[5] = {1,2,3,4,5};
    int *p = (int *)(&a+1);
    int *q = (int *)(a+1);
    printf("%d\n", *(p-1));
    printf("%d\n", *(q-1));
    return 0;
}
