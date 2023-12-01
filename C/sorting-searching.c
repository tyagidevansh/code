#include <stdio.h>
#include <stdlib.h>

void generateRandomArray(int arr[], int n);
void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
void heapSort(int arr[], int n);
void binarySearch(int arr[], int n, int search);

void generateRandomArray(int arr[], int n) {
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n \n");
}

void swap(int arr[], int i, int j){
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int n){
    int temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int temp, min, cur;

    for (int i = 0; i < n - 1; i++) {
        min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


void merge(int arr[], int left, int middle, int right){
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArray[n1], rightArray[n2];

    for (i = 0; i < n1; i++)
        leftArray[i] = arr[left+i];
    for (j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if (left < right){
        int middle = left + (right-left)/2; 

        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);

        merge(arr, left, middle, right);
    }
}

void insertionSort(int arr[], int n) {
    int i,j,key;
    for (i = 0; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, high);
    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right]> arr[largest])
        largest = right; 
    
    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) 
        heapify(arr, n, i);
    
    for (int i = n -  1; i >= 0; i--) {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}

// void binarySearch(int arr[], int n, int search){
//     while(n>0){
//         if (arr[n] > search){
//             n = n/2;
//         } else if (arr[n] < search){
//             n = n+n/2;
//         } else {
//             printf("Element with value %d found at %d. \n", search, n);
//             return;
//         }
//     }
//     printf("%d does not exist within this array ", n);
// }

int main(){
    int n = 10, search;    
    int arr[n];

    generateRandomArray(arr, n);
    printf("Randomly generated array: \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array after bubble sort: \n");
    printArray(arr, n);

    generateRandomArray(arr, n);
    printf("Randomly generated array: \n");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Sorted array after selection sort: \n");
    printArray(arr, n);

    generateRandomArray(arr, n);
    printf("Randomly generated array: \n");
    printArray(arr, n);
    mergeSort(arr, 0, n-1);
    printf("Sorted array after merge sort: \n");
    printArray(arr, n);

    generateRandomArray(arr, n);
    printf("Randomly generated array: \n");
    printArray(arr, n);
    insertionSort(arr, n);
    printf("Sorted array after insertion sort: \n");
    printArray(arr, n);

    generateRandomArray(arr, n);
    printf("Randomly generated array: \n");
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printf("Sorted array after quick sort: \n");
    printArray(arr, n);

    generateRandomArray(arr, n);
    printf("Randomly generated array: \n");
    printArray(arr, n);
    heapSort(arr, n);
    printf("Sorted array after heap sort: \n");
    printArray(arr, n);

    return 0;
}