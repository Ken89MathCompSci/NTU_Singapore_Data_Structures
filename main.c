#include <stdio.h>

int rdigitValue1(int num, int k);

void rdigitValue2(int num, int k, int *result);

int main()
{
    int k;

    int number, digit;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Enter the position: ");
    scanf("%d", &k);

    printf("rdigitValue1(): %d\n", rdigitValue1(number, k));
    rdigitValue2(number, k, &digit);

    printf("rdigitValue2(): %d\n", digit);
    return 0;
}

int rdigitValue1(int num, int k)
{
    if (k == 0)
        return 0;
    else if(k == 1)
        return num%10;
    else
        return rdigitValue1(num/10, k-1);
}

void rdigitValue2(int num, int k, int *result)
{
    if (k == 0)
        *result = 0;
    else if (k == 1)
        *result = num%10;
    else
        rdigitValue2(num/10, k-1, result);
}
