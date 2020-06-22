/*
 * @Author       : fieldxy
 * @Date         : 2020-05-01 18:10:21
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-01 19:37:03
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/double/kernel/main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define NAMESIZE 32
struct score_st
{
    int id;
    char name[NAMESIZE];
    struct list_head node;
    int math;
    int chinese;
};

void printf_s(struct score_st *d)
{
    printf("%d %s %d %d\n",d->id,d->name,d->math,d->chinese);
}

int main()
{
    struct score_st *datap;
    struct list_head * cur;
    LIST_HEAD(head);

    for(int i = 0; i < 7; i++)
    {
        datap = malloc(sizeof(*datap));
        if(datap == NULL)
            exit(1);
        datap->id = i;
        snprintf(datap->name,NAMESIZE,"stu%d",i);
        datap->math = rand() % 100;
        datap->chinese = rand() % 100;

        list_add(&datap->node,&head);
    }

    list_for_each(cur,&head)
    {
        datap = list_entry(cur,struct score_st,node);
        printf_s(datap);
    }
    

    exit(0);
}