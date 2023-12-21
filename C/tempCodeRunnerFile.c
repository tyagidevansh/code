#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
       swap(&arr[i], &arr[min]);
    }
}

void insertionSort(int arr[], int n) {
    int i, j,key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low-1);

    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 8;
    int arr[] = {4, 56, 8, 10, 3, 32, 90, 1, 5};
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}