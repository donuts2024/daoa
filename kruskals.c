#include <stdio.h>

int n, i, j, ne = 1;
int parent[10];
int cost[10][10];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void main() {
    int min, min_cost = 0, a, b, u, v;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("Edge %d: (%d, %d) cost: %d\n", ne++, a, b, min);
            min_cost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", min_cost);
}
