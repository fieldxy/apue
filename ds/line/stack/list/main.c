/*
 * @Author       : fieldxy
 * @Date         : 2020-04-29 07:52:00
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-03 10:24:09
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/stack/list/main.c
 */
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define NAMESIZE    64

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

void printf_s(void * record)
{
    struct score_st *tmp = record;
    printf("%d %s %d %d\n",tmp->id,tmp->name,tmp->math,tmp->chinese);
}


int main()
{
    STACK *st;
    struct score_st tmp;
    st = stack_create(sizeof(struct score_st));
    if(st == NULL)
        exit(1);
    
    for(int i = 0; i <7 ; i++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"stu%d",i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        if(stack_push(st,&tmp))
            exit(1);
    }

    while(1)
    {
        if(stack_pop(st,&tmp) == -1)
            break;
            printf_s(&tmp);
    }
 
     stack_destory(st);

    exit(0);
}