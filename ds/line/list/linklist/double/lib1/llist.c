/*
 * @Author       : fieldxy
 * @Date         : 2020-04-29 07:52:00
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-29 08:30:48
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/double/lib1/llist.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

LLIST * llist_creat(int initsize)
{
    LLIST * new;
    new = malloc(sizeof(*new));
    if(new == NULL)
        return NULL;
    
    new->size = initsize;
    new->head.data = NULL;
    new->head.prev = &new->head;
    new->head.next = &new->head;


    return new;
}

int llist_insert(LLIST *ptr,const void *data,int mode)
{
    
}

llist_find();

llist_delete();

llist_fetch();

llist_travel();

void llist_destory(LLIST * ptr)
{
    struct llist_node_st *cur,*next;
    for(cur = ptr->head.next; cur != &ptr->head; cur = next->next)
    {
        next = cur->next;
        free(cur->data);
        free(cur);
    }
}


