#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
        insertionSort(matrix[i], cols);
    }

    printf("\nMatriz ordenada (cada linha separadamente):\n");
    printMatrix(matrix, rows, cols);

    return 0;
}

