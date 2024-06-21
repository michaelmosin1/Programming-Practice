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
    const int n = 100000000;
    int* arr = generateRandomArrayMassive(n, 100000000);
    printArray(arr, 10);
    //quickSort(arr, 0, n - 1);
    free(arr);
}

int main()
{
    solve();
    return 0;
}
