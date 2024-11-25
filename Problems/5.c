#include <stdio.h>

void multiplyMatrices(int *mat1, int *mat2, int *result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(result + i * c2 + j) = 0;
            for (int k = 0; k < c1; k++) {
                *(result + i * c2 + j) += *(mat1 + i * c1 + k) * *(mat2 + k * c2 + j);
            }
        }
    }
}
int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible. Columns of first matrix must match rows of second matrix.\n");
        return 1;
    }

    int mat1[r1][c1], mat2[r2][c2], result[r1][c2];
    printf("Enter elements of first matrix (%dx%d):\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements of second matrix (%dx%d):\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    multiplyMatrices(&mat1[0][0], &mat2[0][0], &result[0][0], r1, c1, c2);
    printf("Product of the matrices:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
