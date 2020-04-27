#include <stdio.h>
#include <stdlib.h>

int printf_value(int a, int b)
{
    printf("%d   %d\n",a,b);
    return 0;
}

int swap(int *a,int *b)
{
    int tmp;
    tmp = *a;
    *a  = *b;
    *b  = tmp;

}

int main()
{
    int a,b;
    a = 3;
    b = 5;

    printf_value( a,  b);

    swap(&a,&b);
    
    printf_value( a,  b);

    // printf("%d  %d",a,b)
    return 0;
}