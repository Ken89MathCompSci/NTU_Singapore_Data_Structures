#include <stdio.h>

int rSumOddDigits1(int num);

int main()
{
    int num, result;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("rSumOddDigits1(): %d\n", rSumOddDigits1(num));
    return 0;
}

int rSumOddDigits1(int num)
{
    int digit, odddigit=0;

    if (num == 0)
        return odddigit;

    digit = num%10;

    if((digit % 2) != 0)
        odddigit = digit;
    else
        odddigit = 0;

    return rSumOddDigits1(num/10) + odddigit;
}
