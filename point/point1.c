/*
 * @Author       : fieldxy
 * @Date         : 2020-04-03 22:48:49
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-03 23:03:19
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\point\point1.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // int *p = NULL;
    int a[3] = {1,2,3};

    // int *q = (int *)0x7fffcf137b0c; /*百搭类型*/
    int *q = a +4; /*百搭类型*/
    // int *q = a; /*百搭类型*/

    *q = 2345;
    printf("%p ---> %d\n",q,*q);

    exit(0);

}