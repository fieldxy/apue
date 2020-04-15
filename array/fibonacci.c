/*
 * @Author       : field
 * @Date         : 2020-03-31 18:03:34
 * @LastEditTime : 2020-04-15 12:05:17
 * @LastEditors  : fieldxy
 * @FilePath     : \undefinedc:\MyGit\apue\array\fibonacci.c
 * @Description  : fibonacci数列
 */
#include <stdio.h>
#include <string.h>

#define N 10

static void sort1(void)
{
    int tmp,i,j;
    int a[N] = {5,3,6,1,7,8,9,2,4,11};
    
    for()

    for ( i= 0; i < N-1; i++){
        for( j= 0; j < N-1-i; j++){
            if(a[j] > a[j+1]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

static int fibonacci(void)
{
    int i, j, tmp;
    int fib[10] = { 1,1 };

    for (i = 2; i < sizeof(fib) / sizeof(fib[0]); i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    for (i = 0; i < sizeof(fib) / sizeof(fib[0]); i++)
        printf("%d ", fib[i]);
    printf("\n");

    i = 0;
    j = sizeof(fib) / sizeof(fib[0]);

    while (i < j)
    {
        tmp = fib[i];
        fib[i] = fib[j];
        fib[j] = tmp;
        i++;
        j--;
    }

    for (i = 0; i < sizeof(fib) / sizeof(fib[0]); i++)
        printf("%d ", fib[i]);
	printf("\n");

    return 0;
    
}

int main() {
    fibonacci();
    return 0;
}