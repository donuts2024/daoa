#include <stdio.h>

#define N 4 // Size of the puzzle (4x4 for the 15 puzzle)

typedef struct {
    int board[N][N], blankRow, blankCol;
} Puzzle;

void swap(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }

void printPuzzle(Puzzle puzzle) {
    printf("Puzzle State:\n");
    for (int i = 0; i < N; i++, printf("\n"))
        for (int j = 0; j < N; j++) printf("%d%s", puzzle.board[i][j], j == N - 1 ? "" : " ");
}

Puzzle initializePuzzle() {
    Puzzle puzzle;
    printf("Enter the initial state of the puzzle (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            scanf("%d", &puzzle.board[i][j]);
            if (!puzzle.board[i][j]) puzzle.blankRow = i, puzzle.blankCol = j;
        }
    return puzzle;
}

Puzzle generateGoalState() {
    Puzzle goalPuzzle = { .blankRow = N - 1, .blankCol = N - 1 };
    for (int i = 0, value = 1; i < N; i++)
        for (int j = 0; j < N; j++) goalPuzzle.board[i][j] = (value++ % (N * N));
    goalPuzzle.board[N - 1][N - 1] = 0; // Blank tile represented by 0
    return goalPuzzle;
}

int main() {
    Puzzle initialPuzzle = initializePuzzle();
    printPuzzle(initialPuzzle);
    printf("\nGoal State:\n");
    printPuzzle(generateGoalState());
    return 0;
}