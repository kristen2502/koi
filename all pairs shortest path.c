//#ALLpairsShortesPath
#include <stdio.h>

#define INF 9999

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyds(int p[10][10], int n) {
    int i, j, k;

    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}

int main() {
    int p[10][10], n, e, u, v, w, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize matrix
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j)
                p[i][j] = 0;
            else
                p[i][j] = INF;
        }
    }

    // Input edges
    for (i = 1; i <= e; i++) {
        printf("Enter the end vertics of edge %d: ",i);
        scanf("%d %d %d", &u, &v, &w);
        p[u][v] = w;
        // For undirected graph, uncomment:
        // p[v][u] = w;
    }

    printf("\nInitial matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (p[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    floyds(p, n);

    printf("\nShortest path matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (p[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    printf("\nAll-pairs shortest paths:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i != j)
                printf("<%d,%d> = %d\n", i, j, p[i][j]);
        }
    }

    return 0;
}
