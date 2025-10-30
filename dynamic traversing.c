#include <stdio.h>

int main() {
    int rows, columns;
    printf("Enter number of rows for Matrix: ");
    scanf("%d", &rows);
    printf("Enter number of columns for Matrix: ");
    scanf("%d", &columns);

    int x[rows][columns];
    printf("\nInput elements for your Matrix: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Elements of Matrix at position[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &x[i][j]);
        }
    }

    printf("\nNow your Matrix will look like:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }

    return 0;
}