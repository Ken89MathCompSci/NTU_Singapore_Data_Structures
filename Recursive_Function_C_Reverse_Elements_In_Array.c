#include <stdio.h>

void rReverseAr(int ar[], int size);https://github.com/Ken89MathCompSci/NTU_Singapore_Data_Structures/blob/master/main.c

int main()
{
    int ar[10], size, i;

    printf("Enter array size: ");
    scanf("%d", &size);

    printf("Enter %d numbers: ", size);

    for(i=0; i<size; i++)
        scanf("%d", &ar[i]);

    rReverseAr(ar, size);

    printf("rReverseAr(): ");

    for (i=0; i<size; i++)
        printf("%d ", ar[i]);

    return 0;
}

void rReverseAr(int ar[], int size)
{
    int temp;

    if (size == 0 || size == 1)
        return;
    else{
        // swapping op
        temp = ar[0];
        ar[0] = ar[size-1];
        ar[size-1] = temp;
        rReverseAr(&ar[1], size-2);
    }
}
