#include <stdio.h>

void BubbelSort(int a[], int N);
void printArray(int a[], int N);
void swap(int *x, int *y);

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 0, -1, 5, 3, 2, 1};
    int N = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, N); // Before sorting
    BubbelSort(arr, N);
    printArray(arr, N); // After sorting

    return 0;
}

void BubbelSort(int a[], int N)
{
    int i, j, swapped;
    for (i = 0; i < N-1; i++)
    {
        swapped = 0;
        for (j = 0; j < N-i-1; j++)
            if (a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                swapped = 1;
            }
    if(swapped == 0) break;
    }
}

void printArray(int a[], int N)
{
    int i;
    for (i=0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}