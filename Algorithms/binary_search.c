#include <stdio.h>

int binary_search_aux(int *, int, int, int);

int binary_search_aux(int *a, int left, int right, int x) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;

    if (a[mid] < x) {
        return binary_search_aux(a, mid+1, right, x);
    } else if (a[mid] > x) {
        return binary_search_aux(a, left, mid - 1, x);
    } else {
        return mid;
    }
}

int binary_search(int a[], int n, int v) {
    return binary_search_aux(a, 0, n-1, v);
}

int main(int argc, char *argv[]) {
    int a[] = {1, 2, 3, 4, 5, 7, 10 , 12, 20, 100, 203};

    printf("find %d at %d\n", 10, binary_search(a, 11, 10));
    printf("find %d at %d\n", 20, binary_search(a, 11, 20));
    printf("find %d at %d\n", -5, binary_search(a, 11, -5));
    printf("find %d at %d\n", 300, binary_search(a, 11, 300));
    printf("find %d at %d\n", 1, binary_search(a, 11, 1));
    printf("find %d at %d\n", 203, binary_search(a, 11, 203));


    return 0;
}