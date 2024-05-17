#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_N 10

int total_solutions = 0;
int N;
int solutions[MAX_N][MAX_N];

bool isSafe(int row, int col, int board[]) {
    for (int i = 0; i < col; i++) {
        if (board[i] == row || abs(board[i] - row) == abs(i - col)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int col, int board[]) {
    if (col == N) {
        for (int i = 0; i < N; i++) {
            solutions[total_solutions][i] = board[i];
        }
        total_solutions++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col, board)) {
            board[col] = i;
            solveNQueens(col + 1, board);
        }
    }
}

void printSolution(int solution) {
    printf("Solution %d:\n", solution + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (solutions[solution][j] == i) {
                printf("Q%d ", i + 1);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int num_queens;
    printf("Enter the number of queens (N): ");
    scanf("%d", &num_queens);
    if (num_queens < 1 || num_queens > MAX_N) {
        printf("Please enter a number between 1 and %d.\n", MAX_N);
        return 1;
    }
    N = num_queens;
    int board[MAX_N] = {0}; // Initialize board to zeros
    solveNQueens(0, board);
    printf("Total solutions: %d\n", total_solutions);
    for (int i = 0; i < total_solutions; i++) {
        printSolution(i);
    }
    return 0;
}
