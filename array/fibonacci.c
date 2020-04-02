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

#define N 10

static void sort2(void)
{
    int i,j,tmp;
    static int sort[N] = {12,6,7,3,8,13,2,2,22,55};

    printf("\n");
    for(i = 0; i < N; i++)
        printf("%d ",sort[i]);
    printf("\n");
    for(i = 0; i < N-1; i++){
        for(j = i+1; j < N-1; j++){
            if(sort[j] < sort[i]){
                tmp = sort[j];
                sort[j] = sort[i];
                sort[i] = tmp;
            }
        }
    }
    for(i = 0; i < N; i++)
        printf("%d ",sort[i]);
    printf("\n");
}

static void sort1(void)
{
    int i,j,tmp;
    static int sort[N] = {12,6,7,3,8,13,2,2,22,55};

    for(i = 0; i < N; i++)
        printf("%d ",sort[i]);
    printf("\n");
    for(i = 0; i < N-1; i++){
        for(j = 0; j < N-1-i; j++){
            if(sort[j] > sort[j+1]){
                tmp = sort[j];
                sort[j] = sort[j+1];
                sort[j+1] = tmp;
            }
        }
    }
    for(i = 0; i < N; i++)
        printf("%d ",sort[i]);
    printf("\n");

}


static int fibonacci(void)
{
    int i, j, tmp;
    int fib[10] = { 1,1 };
    printf("\n");
    for (i = 2; i < sizeof(fib) / sizeof(fib[0]); i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    for (i = 0; i < sizeof(fib) / sizeof(fib[0]); i++)
        printf("%d ", fib[i]);
    printf("\n");

    i = 0;
    j = sizeof(fib) / sizeof(fib[0]) -1;

#if 1
    while (i < j)
    {
        tmp = fib[i];
        fib[i] = fib[j];
        fib[j] = tmp;
        i++;
        j--;
    }
#endif


    for (i = 0; i < sizeof(fib) / sizeof(fib[0]); i++)
        printf("%d ", fib[i]);
	printf("\n");

    return 0;
    
}

int main() {
    sort1();
    sort2();
    fibonacci();
    return 0;
}