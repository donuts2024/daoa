#include<stdio.h>
#include<stdlib.h>

#define INF 999999

int makeChange(int d[], int n, int amount, int coins[]) {
    int C[n + 1][amount + 1];

    
    for(int i = 0; i <= n; i++)
        C[i][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if (i == 1 && j < d[i - 1])
                C[i][j] = INF;
            else if (i == 1)
                C[i][j] = 1 + C[1][j - d[0]];
            else if (j < d[i - 1])
                C[i][j] = C[i - 1][j];
            else
                C[i][j] = (C[i - 1][j] < 1 + C[i][j - d[i - 1]]) ? C[i - 1][j] : 1 + C[i][j - d[i - 1]];
        }
    }

    int i = n, j = amount, numCoins = 0;
    while (j > 0) {
        if (C[i][j] == C[i - 1][j])
            i = i - 1;
        else {
            coins[numCoins++] = d[i - 1];
            j = j - d[i - 1];
        }
    }

    return C[n][amount];
}

int main() {
    int d[10];
    int n;
    printf("Enter number of denominations: ");
    scanf("%d", &n);

    int amount;
    printf("Enter amount: ");
    scanf("%d", &amount);

    printf("Enter denominations: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    int coins[amount], numCoins;
    numCoins = makeChange(d, n, amount, coins);

    printf("Minimum number of coins needed: %d\n", numCoins);
    printf("Combination of coins: ");
    for(int i = 0; i < numCoins; i++)
        printf("%d ", coins[i]);
    printf("\n");

    return 0;
}
