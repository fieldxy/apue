/*
 * @Author       : field
 * @Date         : 2020-03-31 18:03:34
 * @LastEditTime : 2020-04-01 15:30:10
 * @LastEditors  : field
 * @FilePath     : \apue\array\fibonacci.c
 * @Description  : fibonacci数列
 */
#include <stdio.h>
#include <string.h>

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