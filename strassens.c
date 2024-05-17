#include <stdio.h>
#include <stdlib.h>

void matrixAdd(int n, int A[][n], int B[][n], int C[][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void matrixSubtract(int n, int A[][n], int B[][n], int C[][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[][n], int B[][n], int C[][n])
{
    // Use the normal multiplication if the matrix is very small (e.g., n <= 1)
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize];
    int M5[newSize][newSize], M6[newSize][newSize], M7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Dividing the matrices into 4 sub-matrices
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculating M1 to M7:
    matrixAdd(newSize, A11, A22, temp1);  // temp1 = A11 + A22
    matrixAdd(newSize, B11, B22, temp2);  // temp2 = B11 + B22
    strassen(newSize, temp1, temp2, M1);  // M1 = (A11 + A22) * (B11 + B22)

    matrixAdd(newSize, A21, A22, temp1);  // temp1 = A21 + A22
    strassen(newSize, temp1, B11, M2);    // M2 = (A21 + A22) * B11

    matrixSubtract(newSize, B12, B22, temp1);  // temp1 = B12 - B22
    strassen(newSize, A11, temp1, M3);         // M3 = A11 * (B12 - B22)

    matrixSubtract(newSize, B21, B11, temp1);  // temp1 = B21 - B11
    strassen(newSize, A22, temp1, M4);         // M4 = A22 * (B21 - B11)

    matrixAdd(newSize, A11, A12, temp1);  // temp1 = A11 + A12
    strassen(newSize, temp1, B22, M5);    // M5 = (A11 + A12) * B22

    matrixSubtract(newSize, A21, A11, temp1);  // temp1 = A21 - A11
    matrixAdd(newSize, B11, B12, temp2);       // temp2 = B11 + B12
    strassen(newSize, temp1, temp2, M6);       // M6 = (A21 - A11) * (B11 + B12)

    matrixSubtract(newSize, A12, A22, temp1);  // temp1 = A12 - A22
    matrixAdd(newSize, B21, B22, temp2);       // temp2 = B21 + B22
    strassen(newSize, temp1, temp2, M7);       // M7 = (A12 - A22) * (B21 + B22)

    // Calculating C11, C12, C21, C22:
    matrixAdd(newSize, M1, M4, temp1);         // temp1 = M1 + M4
    matrixSubtract(newSize, temp1, M5, temp2); // temp2 = M1 + M4 - M5
    matrixAdd(newSize, temp2, M7, C11);        // C11 = M1 + M4 - M5 + M7

    matrixAdd(newSize, M3, M5, C12);  // C12 = M3 + M5

    matrixAdd(newSize, M2, M4, C21);  // C21 = M2 + M4

    matrixSubtract(newSize, M1, M2, temp1);    // temp1 = M1 - M2
    matrixAdd(newSize, temp1, M3, temp2);      // temp2 = M1 - M2 + M3
    matrixAdd(newSize, temp2, M6, C22);        // C22 = M1 - M2 + M3 + M6

    // Combining 4 sub-matrices into one
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

void printMatrix(int n, int matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);
    int A[n][n], B[n][n], C[n][n];
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    strassen(n, A, B, C);
    printf("Matrix A:\n");
    printMatrix(n, A);
    printf("Matrix B:\n");
    printMatrix(n, B);
    printf("Matrix C (result of A * B using Strassen's algorithm):\n");
    printMatrix(n, C);
    return 0;
}
