/*
 * @Author       : fieldxy
 * @Date         : 2020-05-02 20:48:08
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-03 08:13:46
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/stack/list/stack.h
 */
#ifndef STACK_H__
#define STACK_H__

#include "llist.h"

typedef LLIST STACK;

STACK *stack_create(int);

int stack_push(STACK *,const void *data);

int stack_pop(STACK *,void *data);

void stack_destory(STACK *);

#endif