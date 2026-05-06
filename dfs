//#DFS
#include <stdio.h>

int a[20][20], reach[20], n;

void dfs(int v) {
    int i;
    reach[v] = 1;

    for (i = 1; i <= n; i++) {
        if (a[v][i] == 1 && !reach[i]) {
            printf("%d -> %d\n", v, i);
            dfs(i);
        }
    }
}

int main() {
    int i, j, count = 0, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize
    for (i = 1; i <= n; i++) {
        reach[i] = 0;
        for (j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    dfs(start);

    // Check connectivity
    for (i = 1; i <= n; i++) {
        if (reach[i])
            count++;
    }

    if (count == n)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is not connected\n");

    return 0;
}
