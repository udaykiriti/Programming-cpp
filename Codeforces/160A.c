#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n; scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    int sum1 = 0, sum2 = arr[n - 1];
    for (int j = 0; j < n - 1; j++)
        sum1 += arr[j];

    int i = 1;
    while (i <= n) {
        if (sum2 > sum1) {
            printf("%d\n", i);
            free(arr);
            return 0;
        } else {
            i++;
            sum2 += arr[n - i];
            sum1 -= arr[n - i];
        }
    }
    free(arr);
    return 0;
}