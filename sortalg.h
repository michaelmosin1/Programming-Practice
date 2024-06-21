#pragma once
#include <stddef.h>
#include <stdint.h>

// static const uint8_t RUN = 128;

void swap(int *a, int *b);

int* generateRandomArrayMassive(size_t size, size_t maxValue);

void heapify(int* arr, size_t n, size_t i);

void heapSort(int *arr, size_t n);

void insertionSort(int *arr, size_t left, size_t right);

void merge(int *arr, int *temp, size_t left, size_t mid, size_t right);

void timSort(int *arr, size_t n);

size_t partition(int *arr, int low, int high);

// static void quickSort(int *arr, size_t low, size_t high) {
//     while (low < high) {
//         if (high - low <= RUN) {
//             for (int i = low + 1; i <= high; i++) {
//                 int key = arr[i];
//                 int j = i - 1;
//                 while (j >= low && arr[j] > key) {
//                     arr[j + 1] = arr[j];
//                     j--;
//                 }
//                 arr[j + 1] = key;
//             }
//             return;
//         }
//         else {
//             int pi = partition(arr, low, high);
//             if (pi - low < high - pi) {
//                 quickSort(arr, low, pi - 1);
//                 low = pi + 1;
//             }
//             else {
//                 quickSort(arr, pi + 1, high);
//                 high = pi - 1;
//             }
//         }
//     }
// }

void quickSort(int* massive, size_t start, size_t end);

void introsort(int *arr, size_t n);
