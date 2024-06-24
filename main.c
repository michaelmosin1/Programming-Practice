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

void solve() 
{
    size_t n = 100000000;
    int* arr = generateRandomArrayMassive(n, n);
    //printArray(arr, 100);
    //heapSort(arr, n);
    timSort(arr, n);
    //mergeSort(arr, n);
    //printArray(arr, 100000);
    free(arr);
}

int main()
{
    solve();
    return 0;
}
