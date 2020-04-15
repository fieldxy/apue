/*
 * @Author       : fieldxy
 * @Date         : 2020-04-08 09:40:53
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-08 10:01:18
 * @Description  : 函数指针
 * @FilePath     : /root/MyGit/apue/func/func_point.c
 */

#include <stdio.h>
#include <stdlib.h>

int add(int a , int b)
{
    return a+b;
}

int sub(int a , int b)
{
    return a-b;
}



int main()
{
    int a = 3, b = 5;
    int ret;

    #if 0
    ret = add(a,b);

    int  (*p) (int, int) ;/* 定义一个指针指向add 函数*/
    int  (*q) (int, int) ;/* 定义一个指针指向sub 函数*/

    p = add;
    q = sub;
    
    ret = p(a,b) - q(a,b);

    #endif
    int (*funcp[2])(int,int); /* 函数指针数组*/

    funcp[0] = add;
    funcp[1] = sub;

    ret = funcp[0](a,b) - funcp[1](a,b);

    printf("add - sub = %d\n",ret);
    exit(0);
}
