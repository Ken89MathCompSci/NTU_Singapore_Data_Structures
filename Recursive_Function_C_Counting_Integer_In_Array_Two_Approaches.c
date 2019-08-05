#include <stdio.h>
#define SIZE 10

int rCountArray(int array[], int n, int a);

int rCountArray2(int array[], int n, int a);

int main()
{
    int array[SIZE];

    int index, count, target, size;

    printf("Enter array size: ");
    scanf("%d", &size);

    printf("Enter %d numbers: ", size);

    for (index = 0; index <size; index++)
        scanf("%d", &array[index]);

    printf("Enter the target: ");
    scanf("%d", &target);

    count = rCountArray(array, size, target);   // approach 1
    printf("rCountArray() = %d\n", count);

    count = rCountArray2(array, size, target);  // approach 2
    printf("rCountArray2() = %d", count);

    return 0;
}

// Approach 1
int rCountArray(int array[], int n, int a)
{
    if (n == 1)
    {
        if(array[0] == a)
            return 1;
        else
            return 0;
    }
    if(array[0] == a)
        return 1+rCountArray(&array[1], n-1, a);
    else
        return rCountArray(&array[1], n-1, a);
}

// Approach 2
int rCountArray2(int array[], int n, int a)
{
    if (n == 1)
    {
        if(array[0] == a)
            return 1;
        else
            return 0;
    }
    if (array[n-1] == a)
        return 1+rCountArray2(&array[0], n-1, a);
    else
        return rCountArray2(&array[0], n-1, a);
}
