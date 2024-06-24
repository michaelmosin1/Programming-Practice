#include "sortalg.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

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

void quickSort(int *arr, size_t start, size_t end)
{
	if (start >= end) return;
	int pivot = arr[(start+end)/2];
	size_t i = start;
	size_t j = end;
	while (i <= j)
    {
        while (arr[i] < pivot && i < end) i++;
        while (arr[j] > pivot && j > start) j--;
        if (i <= j)
        {
            swap(&arr[i], &arr[j]);
            if (i != end) i++;
            if (j != start) j--;
        }
	}
	quickSort(arr, start, j);
	quickSort(arr, i, end);
}

void heapify(int *arr, size_t n, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, size_t n)
{
    for (size_t i = n / 2; i > 0; i--) heapify(arr, n, i - 1);
    for (size_t i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void IntroQuickSort(int *arr, size_t start, size_t end, size_t depth)
{
    if (depth == 0)
    {
        heapSort(arr, end - start + 1);
        return;
    }
	if (start >= end) return;
	int pivot = arr[(start+end)/2];
	size_t i = start;
	size_t j = end;
	while (i <= j)
    {
        while (arr[i] < pivot && i < end) i++;
        while (arr[j] > pivot && j > start) j--;
        if (i <= j)
        {
            swap(&arr[i], &arr[j]);
            if (i != end) i++;
            if (j != start) j--;
        }
	}
	IntroQuickSort(arr, start, j, depth - 1);
	IntroQuickSort(arr, i, end, depth - 1);
}

void introSort(int *arr, size_t n)
{
    size_t max_depth = log(n) / 2;
    IntroQuickSort(arr, 0, n - 1, max_depth);
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
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];
}

void timSort(int *arr, size_t n) {
    int *temp = (int *)malloc(n * sizeof(int));
    if (temp == NULL) return;
    for (size_t i = 0; i < n; i += RUN)
        insertionSort(arr, i, (i + RUN - 1 < n) ? (i + RUN - 1) : (n - 1));
    for (size_t size = RUN; size < n; size = 2 * size)
    {
        for (size_t left = 0; left < n; left += 2 * size)
        {
            size_t mid = left + size - 1;
            size_t right = (left + 2 * size - 1 < n) ? (left + 2 * size - 1) : (n - 1);
            if (mid < right) merge(arr, temp, left, mid, right);
        }
    }
    free(temp);
}
