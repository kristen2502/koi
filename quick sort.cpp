// QuickSort
#include <stdio.h>

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int a[50], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
     printf("\nEnter elements %d:",i+1);
     scanf("%d", &a[i]);
    }
    printf("\n The array elements before sorting:\n");
    for(i=0;i<n;i++)
    {
    	printf("%5d",a[i]);
	}

    quicksort(a, 0, n - 1);

    printf("\n The array element after Sorted :\n");
    for(i = 0; i < n; i++) {
        printf("%5d",a[i]);
    }

    return 0;
}

void quicksort(int a[], int low, int high) {
    int p;
    if (low < high) {
        p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (1) {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            break;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}
