#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int tsp(int cities, int graph[MAX_CITIES][MAX_CITIES], int start, int mask, int *path)
{
    int min_cost = INT_MAX;
    int visited_all = (1 << cities) - 1;
    int min_path[MAX_CITIES];

    if (mask == visited_all)
    {
        path[0] = start;
        return graph[start][0];
    }

    for (int city = 0; city < cities; city++)
    {
        if (!(mask & (1 << city)))
        {
            int new_mask = mask | (1 << city);
            int new_path[MAX_CITIES];
            int cost = graph[start][city] + tsp(cities, graph, city, new_mask, new_path);
            if (cost < min_cost)
            {
                min_cost = cost;
                min_path[0] = start;
                for (int i = 0; i < cities; i++)
                {
                    min_path[i + 1] = new_path[i];
                }
            }
        }
    }

    for (int i = 0; i < cities; i++)
    {
        path[i] = min_path[i];
    }

    return min_cost;
}

int main()
{
    int graph[MAX_CITIES][MAX_CITIES];
    int cities, start;

    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &cities);

    printf("Enter the distance between cities:\n");
    for (int i = 0; i < cities; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            printf("Distance from city %d to city %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting city: ");
    scanf("%d", &start);

    int path[MAX_CITIES];
    int min_cost = tsp(cities, graph, start, 1, path);

    printf("Minimum cost: %d\n", min_cost);
    printf("Sequence of travel: ");
    for (int i = 0; i < cities; i++)
    {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); // to complete the cycle

    return 0;
}
