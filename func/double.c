/*
 * @Author       : fieldxy
 * @Date         : 2020-04-06 20:31:50
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-07 22:38:28
 * @Description  : In User Settings Edit
 * @FilePath     : /root/MyGit/apue/func/double.c
 */
#include <stdio.h>
#include <stdlib.h>

#define M  3
#define N  4

int printf_arr(int *a,int n,int m)
{
    int i,j;
    #if 0
    for( i = 0; i < M; i++){
        for( j = 0; j < N; j ++){
            printf("%4d ",a[i][j]);
        }
        printf("\n");
    }
    #endif
    for ( i = 0; i < n; i++)
        printf("%d ",a[i]);

    printf("\n");
    return 0;
}
// int printf_arr1(int (*a)[N],int m,int n)
int printf_arr1(int a[][N],int m,int n)
{
    int i,j;
    printf("sizeof(a) = %d\n",sizeof(a));
    #if 1
    for( i = 0; i < m; i++){
        for( j = 0; j < n; j ++){
            printf("%4d ",a[i][j]);
        }
        printf("\n");
    }
    #endif

    printf("\n");
    return 0;
}

int main()
{
    int i,j;
    int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};
    
#if 0
    printf_arr(&a[0][0],M*N,0);
#endif

    printf("sizeof(a) = %d\n",sizeof(a));
    printf("sizeof(a)/sizeof(*a) = %d\n",sizeof(a)/sizeof(*a));
    printf_arr1(&a[0][0],M,N);
    return 0;
}