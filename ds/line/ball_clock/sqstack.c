/*
 * @Author       : fieldxy
 * @Date         : 2020-05-05 18:53:00
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-05 18:57:01
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/ball_clock/sqstack.c
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
int st_push(sqstack *st,type *data)
{
    if(st->top == (SIZE-1))
        return -1;
    
    st->data[++st->top] = *data;
    
        return 0;
}
int st_pop(sqstack *st,type *data)
{
    if(st_isempty(st))
        return -1;
    *data = st->data[st->top--];
    return 0;
}
int st_top(sqstack *st,type *data)
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
        printf("%d ",st->data[i]);
    printf("\n");
}
void st_destory(sqstack *st)
{
    free(st);
}