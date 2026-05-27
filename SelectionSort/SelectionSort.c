#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 101 // Maximum size of the array
void swap(int *x, int *y);
void SelectionSort(int list[], int n);

int main(void)
{
    int i, n;
    int list[MAX_SIZE];
    
    srand((unsigned)time(NULL)); // Seed the random number generator

    printf("Enter the number of elements in the array (1-100): ");
    scanf("%d", &n);
    if(n < 1 || n > MAX_SIZE)
    {
        printf("Invalid number of elements. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }
    for(i = 0; i < n; i++)
    {
        list[i] = rand() % 100; // Generate random numbers between 0 and 99
        printf("%d ", list[i]);
    }
    printf("\n");
    SelectionSort(list, n);
    printf("Sorted array: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}

void SelectionSort(int list[], int n)
{
    // Sort the list using selection sort algorithm
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (list[j] < list[min])
            {
                min = j;
            }
        }
    swap(&list[i], &list[min]);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}