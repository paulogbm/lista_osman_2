#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    int j;
    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
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

void printMatrix(int mat[][5], int rows, int cols) {
	int i;
	int j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

int main() {
    int rows = 3;
    int cols = 5;
	int i;
	
    int matrix[3][5] = {
        {23, 15, 8, 7, 1},
        {12, 19, 4, 6, 3},
        {9, 11, 21, 5, 17}
    };

    printf("Matriz original:\n");
    printMatrix(matrix, rows, cols);

    for (i = 0; i < rows; i++) {
        quickSort(matrix[i], 0, cols - 1);
    }

    printf("\nMatriz ordenada (cada linha separadamente):\n");
    printMatrix(matrix, rows, cols);

    return 0;
}

