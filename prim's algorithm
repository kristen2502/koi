//#Prim's Algorithm
#include <stdio.h>
#include <conio.h>

int cost[10][10], n;

void prim() {
    int i, j, startVertex = 0;
    int visited[10] = {0};
    int min, x = 0, y = 0;
    int minCost = 0, edges = 0;

    visited[0] = 1; // Start from vertex 0

    while (edges < n - 1) {
        min = 999;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("Edge %d: (%d -> %d) cost = %d\n", edges + 1, x, y, min);

        minCost += min;
        visited[y] = 1;
        edges++;
    }

    printf("Minimum cost = %d\n", minCost);
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 with large number (no edge)
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    prim();
    getch();
    return 0;
}
