#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    int j;
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    int i;
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int j = 0;
    i = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void fillArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int sizes[] = {1000, 5000, 10000, 50000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    int i, j;
    for (i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int arr[size], arr_copy[size];
        fillArray(arr, size);
        for (j = 0; j < size; j++) {
            arr_copy[j] = arr[j];
        }

        clock_t start = clock();
        bubbleSort(arr, size);
        clock_t end = clock();
        double elapsed_time_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;

        for (j = 0; j < size; j++) {
            arr[j] = arr_copy[j];
        }
        start = clock();
        quickSort(arr, 0, size - 1);
        end = clock();
        double elapsed_time_quicksort = ((double)(end - start)) / CLOCKS_PER_SEC;

        for (j = 0; j < size; j++) {
            arr[j] = arr_copy[j];
        }
        start = clock();
        mergeSort(arr, 0, size - 1);
        end = clock();
        double elapsed_time_mergesort = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Tamanho do array: %d\n", size);
        printf("Tempo (bolha): %.6f segundos\n", elapsed_time_bubble);
        printf("Tempo (quicksort): %.6f segundos\n", elapsed_time_quicksort);
        printf("Tempo (mergesort): %.6f segundos\n\n", elapsed_time_mergesort);
    }

    return 0;
}

