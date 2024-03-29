#include <stdio.h>

int rSumUp1(int n);

void rSumUp2(int n, int *result);

int main()
{
    int n, result;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Using call by value (return)
    printf("rSumUp1 (): %d\n", rSumUp1(n));

    // Using call by reference
    rSumUp2(n, &result);
    printf("rSumUp2(): %d", result);

    return 0;
}

int rSumUp1(int n)
{
    if (n == 1)
        return 1;
    else
        return n + rSumUp1(n-1);
}

void rSumUp2(int n, int *result)
{
    if(n == 1)
        *result = 1;
    else
    {
        rSumUp2(n-1, result);
        *result += n;
    }
}
