#include <stdio.h>
#include <stdlib.h>
/**
 *  3! = 3*2*1;
 *  4! = 4*3*2*1;
 *  n! = n(n-1)!
 *  1! = 1;
 *  0! = 1;
**/
int func(int n);
int main(void)
{
    int n;
    int res;
    scanf("%d",&n);

    res = func(n);

    printf("%d! = %d\n",n,res);

    return 0;
}

int func(int n)
{
    int res;
    printf("%d\n",n);
    if(n < 0)
        return -1;
    if ( n == 0 | n==1)
        return 1;
    res = n * func(n-1);
    printf("%d! = %d\n",n,res);
    return res;
}