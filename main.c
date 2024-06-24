#include "sortalg.h"
#include <stdlib.h>
#include <stdio.h>


void printArray(int *arr, size_t n)
{
    for (size_t i=0; i<n; ++i){
        printf("%d", arr[i]);
        printf(" ");
    }
    printf("\n");
}

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void solve() 
{
    size_t n = 100000000;
    int* arr = generateRandomArrayMassive(n, n);
    //printArray(arr, 1000);
    //quickSort(arr, 0, n - 1);
    //heapSort(arr, n);
    //timSort(arr, n);
    introSort(arr, n);
    //insertionSort(arr, 0, n - 1);

    //qsort(arr, n, sizeof(int), cmp );
    free(arr);
}

int main()
{
    solve();
    return 0;
}
