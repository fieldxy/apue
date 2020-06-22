#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c);
int min(int a, int b, int c);
int dist(int i, int j, int k);
int printf_value(int max, int min, int dist);

int main()
{
    int a,b,c;

    a = 5; 
    b = 2;
    c = 8;
    
    printf_value(max(a,b,c),min(a,b,c),dist(a,b,c));

    return 0;

}


int max(int a, int b, int c)
{
    int tmp;
    tmp = a > b ? a : b;
    return tmp > c ? tmp : c;

}

int min(int a, int b, int c)
{
    int tmp;
    tmp = a < b ? a : b;
    return tmp < c ? tmp : c;

}

int dist(int i, int j, int k)
{
    return max( i, j, k) - min( i, j, k);
}

int printf_value(int max, int min, int dist)
{
    printf("max = %d\n",max);
    printf("min = %d\n",min);
    printf("dist = %d\n",dist);
}