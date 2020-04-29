/*
 * @Author       : fieldxy
 * @Date         : 2020-04-29 07:52:00
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-29 08:22:07
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/double/lib1/main.c
 */
#include <stdlib.h>
#include <stdio.h>
#include "llist.h"

#define NAMESIZE 32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

int main()
{
    LLIST *headler;
    struct score_st tmp;

    headler = llist_creat(sizeof(struct score_st));

    for(int i = 0; i < 7 ; i++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"std%d",i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        llist_insert(headler,&tmp,LLIST_FORWARD);
    }

    llist_insert();

    llist_travel(headler);

    llist_destory(headler);    


    exit(0);
}