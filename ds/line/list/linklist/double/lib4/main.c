/*
 * @Author       : fieldxy
 * @Date         : 2020-04-29 07:52:00
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-01 12:01:07
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/double/lib4/main.c
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

void print_s(const void *record)
{
    const struct score_st *r = record;
    printf("%d %s %d %d\n",r->id,r->name,r->math,r->chinese);

}

static int id_cmp(const void * key, const void * record)
{
    const int *k = key;
    const struct score_st *r = record;

    return (*k - r->id);
    
}
int main()
{
    LLIST *headler;
    struct score_st tmp;
    int ret;

    headler = llist_creat(sizeof(struct score_st));
    if(headler == NULL)
        exit(1);

    for(int i = 0; i < 7 ; i++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"std%d",i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        ret = llist_insert(headler,&tmp,LLIST_FORWARD);
        if(ret)
            exit(1);
    }

    llist_travel(headler,print_s);

    llist_destory(headler);
    // headler->destory(headler);    


    exit(0);
}