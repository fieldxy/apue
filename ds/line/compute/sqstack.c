/*
 * @Author       : fieldxy
 * @Date         : 2020-05-04 10:37:54
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-05 17:14:22
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/compute/sqstack.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"

/*创建一个顺序存储的栈*/
sqstack *st_create(void)
{
    sqstack * st;
    st = malloc(sizeof(*st));
    if(st == NULL)
        return NULL;
    st->top = -1;
    return st;
}
/**/
int st_isempty(sqstack *st)
{
    return(st->top == -1);
}
int st_push(sqstack *st,datatype *data)
{
    if(st->top == (MAXSIZE-1))
        return -1;
    
    st->data[++st->top] = *data;
    
        return 0;
}
int st_pop(sqstack *st,datatype *data)
{
    if(st_isempty(st))
        return -1;
    *data = st->data[st->top--];
    return 0;
}
int st_top(sqstack *st,datatype *data)
{
    if(st_isempty(st))
        return -1;
    *data = st->data[st->top];
    return 1;
}
void st_travel(sqstack *st)
{
    if(st_isempty(st)) 
        return ;
    for(int i = 0; i <= st->top;i++)
        printf("st[%d]:%d ",i,st->data[i]);
    printf("\n");
}
void st_destory(sqstack *st)
{
    free(st);
}