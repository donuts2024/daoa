#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int data) {
    if (top < MAX - 1)
        stack[++top] = data;
}

void pop() {
    if (top >= 0)
        top--;
}

int isStackEmpty() {
    return top == -1;
}

void display(int weights[], int n) {
    printf("{ ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", weights[stack[i]]);
    }
    printf("}\n");
}

void sumOfSubsets(int weights[], int target, int sum, int total, int n) {
    if (sum == target) {
        display(weights, n);
        return;
    }

    if (n >= total || sum > target)
        return;

    push(n);
    sumOfSubsets(weights, target, sum + weights[n], total, n + 1);

    pop();
    sumOfSubsets(weights, target, sum, total, n + 1);
}

int main() {
    int weights[MAX], n, target, total = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
        total += weights[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("The subsets with the sum %d are:\n", target);
    sumOfSubsets(weights, target, 0, n, 0);

    return 0;
}
