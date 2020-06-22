/*
 * @Author       : fieldxy
 * @Date         : 2020-05-02 20:48:08
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-03 10:27:23
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/stack/list/stack.c
 */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

STACK *stack_create(int initsize)
{
    return llist_creat(initsize);
}

int stack_push(STACK *ptr,const void *data)
{
    return llist_insert(ptr,data,LLIST_FORWARD);
}

static int always_match(const void *p1,const void *p2)
{
    return 0;
}
int stack_pop(STACK *ptr,void *data)
{
    return llist_fetch(ptr,(const void *)0,always_match,data);
}
void stack_destory(STACK *ptr)
{
    llist_destory(ptr);
}