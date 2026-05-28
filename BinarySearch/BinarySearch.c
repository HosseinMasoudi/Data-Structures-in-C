#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1 )

int BinSearch(int list[], int SearchNum, int left, int right);
int BinSearchRecursive(int list[], int SearchNum, int left, int right);

int main()
{
    int list[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int SearchNum = 7;
    int left = 0;
    int right = sizeof(list) / sizeof(list[0]) - 1;

    int result = BinSearch(list, SearchNum, left, right);
    if(result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the list.\n");

    return 0;
}

int BinSearch(int list[], int SearchNum, int left, int right)
{
    /*
    This function performs a binary search on the given list for the SearchNum.
    It takes the list, the number to search for, and the left and right indices as parameters.
    The function returns the index of the SearchNum if found, or -1 if not found.
    */
    int middle;
    while(left <= right)
    {
        middle = (left + right) / 2;
        switch(COMPARE(list[middle], SearchNum))
        {
            case -1:
                left = middle + 1;
                break;
            case 0:
                return middle;
            case 1:
                right = middle - 1;
                break;
        }
    }
    return -1;
}

int BinSearchRecursive(int list[], int SearchNum, int left, int right)
{
    /*
    This function performs a recursive binary search on the given list for the SearchNum.
    It takes the list, the number to search for, and the left and right indices as parameters.
    The function returns the index of the SearchNum if found, or -1 if not found.
    */
    if(left > right)
        return -1;

    int middle = (left + right) / 2;
    switch(COMPARE(list[middle], SearchNum))
    {
        case -1:
            return BinSearchRecursive(list, SearchNum, middle + 1, right);
        case 0:
            return middle;
        case 1:
            return BinSearchRecursive(list, SearchNum, left, middle - 1);
    }
}