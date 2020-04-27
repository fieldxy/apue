/*
 * @Author       : fieldxy
 * @Date         : 2020-04-26 15:31:44
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-27 21:36:50
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/simple/nohead/list.c
 */
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#if 0
struct node_st * list_insert(struct node_st *list,struct score_st * data)
{
    struct node_st *new;
    new = malloc(sizeof(*new));
    if(new == NULL)
        return NULL;
    new->data = *data;    
    new->next = list;
    list = new;
    return list;
}
#else

int list_insert(struct node_st **list,struct score_st * data)
{
    struct node_st *new;
    new = malloc(sizeof(*new));
    if(new == NULL)
        return -1;
    new->data = *data;    
    new->next = *list;
    *list = new;
    return 0;
}
#endif

int list_display(struct node_st *me)
{
    struct node_st *list;
    list = me;
    for(list = me;list != NULL;list = list->next)
        printf("id: %d name: %s math: %d chinese: %d\n",list->data.id,list->data.name,list->data.math,list->data.chinese);
    return 0;
}

