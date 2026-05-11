//#Knapsack
#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i, u;

    u = capacity;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++) {
        if (weight[i] <= u) {
            x[i] = 1.0;
            tp += profit[i];
            u -= weight[i];
        } else {
            x[i] = u / weight[i];
            tp += x[i] * profit[i];
            break;
        }
    }

    printf("\nResult vector:\n");
    for (i = 0; i < n; i++)
        printf("%f\t", x[i]);

    printf("\nMaximum profit = %f\n", tp);
}

int main() {
    float weight[20], profit[20], ratio[20], capacity;
    int n, i, j;

    printf("Enter number of objects: ");
    scanf("%d", &n);

    printf("Enter weights and profits:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    // Sort by profit/weight ratio (descending)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // swap ratio
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    printf("Enter capacity: ");
    scanf("%f", &capacity);

    knapsack(n, weight, profit, capacity);

    return 0;
}
