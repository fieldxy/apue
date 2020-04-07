/*
 * @Author       : fieldxy
 * @Date         : 2020-04-07 23:38:37
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-07 23:49:10
 * @Description  : In User Settings Edit
 * @FilePath     : /root/MyGit/apue/func/douarr.c
 */
#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 4

float average_score(int *p, int n)
{
    int i;
    float sum = 0;
    for(i = 0; i < n; i++)
        sum += p[i];
    return sum/n;
}

void find_num(int (*p)[N],int num)
{
    int i;
    for(i = 0; i < N; i++){
        printf("%d ",*(*(p+num) + i));
    }
    printf("\n");
}

int main()
{
    int i,j;
    
    int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int num = 1;

    printf("average = %f\n",average_score(*a,M*N));

    find_num(a,num);

    return 0;
}