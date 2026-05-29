#include <stdio.h>
#define MAX_SIZE 15 //max size of square

int main(void)
{
    static int square[MAX_SIZE][MAX_SIZE];
    int i, j, row, column, counter, size;
    printf("Enter the size of the magic square (odd number between 1 and 15): ");
    scanf("%d", &size);
    if (size < 1 || size > MAX_SIZE || size % 2 == 0) {
        printf("Invalid size. Please enter an odd number between 1 and 15.\n");
        return 1;
    }

    // Initialize the square with zeros
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            square[i][j] = 0;

    i = 0;
    j = (size-1)/2;
    square[i][j] = 1;
    for(counter = 2; counter <= size*size; counter++)
    {
        row = (i - 1 < 0) ? (size - 1) : (i - 1); // Move up
        column = (j - 1 < 0) ? (size - 1) : (j - 1); // Move left
        if (square[row][column])
        {
            (++i) % size;
        }
        else
        {
            i = row;
            j = (j-1 < 0) ? (size - 1) : --j;
        }
        square[i][j] = counter;
    }
    printf("The %d x %d magic square is:\n", size, size);
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            printf("%4d ", square[i][j]);
        printf("\n");
    }
    
    return 0;
}