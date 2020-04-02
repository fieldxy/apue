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

static void primer(void)
{
    char primer[1001]={0};
    int i,j;
    for(i = 2; i < 1001; i++)
    {
        if(primer[i] == 0){
            for(j = i*2; j < 1001; j+=i){
                primer[j] = -1;
            }
        }
    }

    for(i = 2; i < 1001; i++)
        if(primer[i] == 0)
            printf("%d is a primer .\n",i);
    printf("\n");
}

static void base_convert(void)
{
    int num,base;
    int cha_arr[128] ;
    int i,tmp,j;
    printf("please input convert num = ");
    scanf("%d",&num);
    printf("please input base = ");
    scanf("%d",&base);
    
    printf("num = %d, base = %d\n",num,base);

    for(i=0; num != 0; i ++){
        cha_arr[i] = num % base;
        num = num / base;
    }

    printf("i = %d, j = %d \n",i,j);
    for(i--;i >= 0; i--){
        if(cha_arr[i] >= 10)
            printf("%c ",cha_arr[i]- 10 + 'A');
        else
            printf("%d ",cha_arr[i]);
    }

    printf("\n");
}


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
#if 0
    sort1();
    sort2();
    fibonacci();
    base_convert();
#endif

    primer();
    return 0;
}