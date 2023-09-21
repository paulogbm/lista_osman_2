#include <stdio.h>

typedef struct {
    int row;
    int col;
} Position;

Position searchValueInMatrix(int matrix[][3], int numRows, int numCols, int value) {
    Position position = {-1, -1};
    int i, j;

    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            if (matrix[i][j] == value) {
                position.row = i;
                position.col = j;
                return position;
            }
        }
    }

    return position;
}

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int value;

    printf("Digite o valor a ser procurado na matriz: ");
    scanf("%d", &value);

    Position result = searchValueInMatrix(matrix, 3, 3, value);

    if (result.row != -1 && result.col != -1)
        printf("O valor foi encontrado na posicao (%d, %d)\n", result.row, result.col);
    else
        printf("O valor não foi encontrado na matriz.\n");

    return 0;
}

