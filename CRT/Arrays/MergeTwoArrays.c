#include <stdio.h>

#define SIZE1 6
#define SIZE2 6
#define SIZE3 (SIZE1 + SIZE2)
#define SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
int main() {
    int arr1[SIZE1] = {1, 4, 6, 7, 9, 10};
    int arr2[SIZE2] = {2, 5, 8, 11, 13, 16};
    int arr3[SIZE3];

    int i = 0, j = 0, k = 0;

    while (i < SIZE1 && j < SIZE2) {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i < SIZE1)
        arr3[k++] = arr1[i++];
    while (j < SIZE2)
        arr3[k++] = arr2[j++];

    printf("\nThe new sorted merged array is:\n");
    for (int i = 0; i < SIZE3; i++)
        printf("%d ", arr3[i]);

    printf("\n");
    return 0;
}
