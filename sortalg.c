#include "sortalg.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

static const int RUN = 128;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* generateRandomArrayMassive(size_t size, size_t maxValue)
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    srand(now.tv_nsec);
    int* arr = (int *)malloc(sizeof(int)*size);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand()%maxValue;
    }
    return arr;
}

void quickSort(int* massive, size_t start, size_t end)
{
	if (start > end) return;
	int pivot = massive[(start+end)/2]%10;
	int i = start;
	int j = end;
	while (i <= j)
    {
        while ((massive[i]%10) > pivot) i++;
        while ((massive[j]%10) < pivot) j--;
        if (i <= j)
        {
            swap(&massive[i], &massive[j]);
            i++;
            j--;
        }
	}
	quickSort(massive, start, j);
	quickSort(massive, i, end);
}

void heapify(int* arr, size_t n, size_t i)
{
    size_t largest = i;
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;
    while (l < n)
    {
        if (l < n && arr[l] > arr[largest])
            largest = l;
        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            i = largest;
            l = 2 * i + 1;
            r = 2 * i + 2;
        }
        else
        {
            break;
        }
    }
}

void heapSort(int *arr, size_t n)
{
    for (size_t i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (size_t i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void insertionSort(int *arr, size_t left, size_t right)
{
    for (size_t i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        size_t j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int *arr, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left;
    size_t j = mid + 1;
    size_t k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void timSort(int *arr, size_t n) {
    int *temp = (int *)malloc(n * sizeof(int));
    if (temp == NULL)
    {
        return;
    }
    for (size_t i = 0; i < n; i += RUN)
    {
        insertionSort(arr, i, (i + RUN - 1 < n) ? (i + RUN - 1) : (n - 1));
    }

    for (size_t size = RUN; size < n; size = 2 * size)
    {
        for (size_t left = 0; left < n; left += 2 * size)
        {
            size_t mid = left + size - 1;
            size_t right = (left + 2 * size - 1 < n) ? (left + 2 * size - 1) : (n - 1);
            if (mid < right)
            {
                merge(arr, temp, left, mid, right);
            }
        }
    }
    free(temp);
}

// size_t partition(int *arr, int low, int high)
// {
//     int pivot = arr[high];
//     int i = (low - 1);
//     for (size_t j = low; j <= high - 1; j++)
//     {
//         if (arr[j] <= pivot)
//         {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return (i + 1);
// }

void introsort(int *arr, size_t n) {
    int maxDepth = 2 * (int)(log(n) / log(2));
    quickSort(arr, 0, n - 1);
    if (n > 1 && maxDepth > 0)
        heapSort(arr, n);
}