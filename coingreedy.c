#include <stdio.h>
#define COINS 4
#define MAX 20

int coins[COINS] = { 1,5,6,9 };

void findMin(int cost)
{
    int coinList[MAX] = { 0 };
    int i, k = 0;

    for (i = COINS - 1; i >= 0; i--) {
        while (cost >= coins[i]) {
            cost -= coins[i];
            // Add coin in the list
            coinList[k++] = coins[i];
        }
    }

    printf("Number of coins are: %d\n", k);
    printf("Coins used: ");
    for (i = 0; i < k; i++) {
        // Print each coin
        printf("%d ", coinList[i]);
    }
    printf("\n");
}

int main(void)
{
    int n;

    printf("Enter the amount: ");
    
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    findMin(n);

    return 0;
}
