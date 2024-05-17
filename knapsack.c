#include <stdio.h>

int main() {
    float weight[50], profit[50], ratio[50], Totalvalue = 0.0, temp, capacity;
    int n, i, j;
    float selected[50] = {0};  // To keep track of the amount of each item selected

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Weight and Profit for item[%d]:\n", i);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter the capacity of knapsack:\n");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sorting items by profit/weight ratio in descending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap weights
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap profits
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    printf("Knapsack problems using Greedy Algorithm:\n");
    for (i = 0; i < n; i++) {
        if (weight[i] > capacity) {
            break;
        } else {
            selected[i] = weight[i];
            Totalvalue = Totalvalue + profit[i];
            capacity = capacity - weight[i];
        }
    }

    if (i < n) {
        selected[i] = capacity;  // Fractional part of the next item
        Totalvalue = Totalvalue + (ratio[i] * capacity);
    }

    printf("\nThe maximum value is: %f\n", Totalvalue);

    // Print the selected items
    printf("Items selected:\n");
    for (i = 0; i < n; i++) {
        if (selected[i] > 0) {
            if (selected[i] == weight[i]) {
                printf("Item[%d] ", i);
            } else {
                printf("Item[%d]*%.2f ", i, selected[i] / weight[i]);
            }
        }
    }
    printf("\n");

    return 0;
}
