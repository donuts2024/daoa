#include <stdio.h>
            #include <string.h>

           #define MAX_LENGTH 100

           #define MAX(x, y) ((x) > (y) ? (x) : (y))

           void lcs(char X[], char Y[], int m, int n, char result[]) {
    int L[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0; 
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;  
            else
                L[i][j] = MAX(L[i - 1][j], L[i][j - 1]);  
        }
    }

    int index = L[m][n];
    result[index] = '\0'; // Null terminate the LCS string

    // Start from the right-most bottom-most corner and store characters
    i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            result[index - 1] = X[i - 1];
            i--; j--; index--; 
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
}

int main() {
    char X[MAX_LENGTH], Y[MAX_LENGTH], result[MAX_LENGTH];

    printf("Enter the first text: ");
    fgets(X, MAX_LENGTH, stdin);
    X[strcspn(X, "\n")] = '\0'; 

    printf("Enter the second text: ");
    fgets(Y, MAX_LENGTH, stdin);
    Y[strcspn(Y, "\n")] = '\0'; 
    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n, result);

    printf("Length of Longest Common Subsequence: %d\n", strlen(result));
    printf("Longest Common Subsequence: %s\n", result);
    
    return 0;
}
