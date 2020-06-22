/*
 * @Author       : fieldxy
 * @Date         : 2020-04-05 21:56:25
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-06 20:24:24
 * @Description  : In User Settings Edit
 * @FilePath     : /root/MyGit/apue/func/arr.c
 */
#include <stdio.h>
#include <stdlib.h>

void func(int *p,int n)
{
    int i = 0,m,j,tmp;
    m = (n - 1) / 2;

    for(;i <= m ; i++){
        j = n - 1 - i;
        tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;
    }

}
#if 0
int print_arr(int *p,int n)
{
    int i;
    printf("%s:%d\n",__FUNCTION__,sizeof(p));
    for(i = 0; i < n; i++)
        printf("%d ",*(p+i));

    printf("\n");
}
#endif

int main(int argc, char **argv)
{
    int i;
    int a[] = {1,3,5,7,9};

    for( i = 0; i < sizeof(a) / sizeof(*a) ; i++)
        printf("%d ",a[i]);
        
    printf("\n");
  
    func(a,sizeof(a) / sizeof(*a));
        
    for( i = 0; i < sizeof(a) / sizeof(*a) ; i++)
        printf("%d ",a[i]);
    
    printf("\n");


#if 0
    printf("%s:%d\n",__FUNCTION__,sizeof(a));

    print_arr(a,sizeof(a)/sizeof(*a));
#endif
    return 0;
}