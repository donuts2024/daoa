#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void matrixChainOrder(int dimensions[], int n) {
    int costMatrix[MAX_SIZE][MAX_SIZE];
    int splitMatrix[MAX_SIZE][MAX_SIZE];
    int i, j, k, length;

    // Initialize the cost matrix
    for (i = 1; i < n; i++) {
        costMatrix[i][i] = 0;
    }

    // L is chain length.
    for (length = 2; length < n; length++) {
        for (i = 1; i <= n - length; i++) {
            j = i + length - 1;
            costMatrix[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                int tempCost = costMatrix[i][k] + costMatrix[k + 1][j] + (dimensions[i - 1] * dimensions[k] * dimensions[j]);

                if (tempCost < costMatrix[i][j]) {
                    costMatrix[i][j] = tempCost;
                    splitMatrix[i][j] = k;
                }
            }
        }
    }

    printf("The Cost Matrix:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (i > j) {
                printf("\t");
            } else {
                printf("%d\t", costMatrix[i][j]);
            }
        }
        printf("\n");
    }

    printf("Minimum number of multiplications: %d\n", costMatrix[1][n-1]);
    printf("\n");
}

int main() {
    int dimensions[MAX_SIZE];
    int size;

    printf("Enter the number of matrices: ");
    scanf("%d", &size);
    size++; // Number of dimensions is one more than the number of matrices

    printf("Enter the dimensions: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &dimensions[i]);
    }

    matrixChainOrder(dimensions, size);

    return 0;
}
