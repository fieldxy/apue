/*
 * @Author       : fieldxy
 * @Date         : 2020-04-26 15:31:44
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-27 23:00:05
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

int list_delete(struct node_st **me)
{
    struct node_st *list;

    if(*me == NULL)
        return -1;
    list = *me;    
    * me = (*me) ->next;
    
    free(list);

    return 0;
}
#if 0
int list_fine(struct node_st * me,int id)
{
    struct node_st *list;
    for(list = me; list != NULL; list=list->next)
    {
        if(list->data.id == id)
        {
            printf("%d %s %d %d",list->data.id,list->data.name,list->data.math,list->data.chinese);
            return 0;

        }
    }
}
#else
struct score_st * list_fine(struct node_st * me,int id)
{
    struct node_st *list;
    for(list = me; list != NULL; list=list->next)
    {
        if(list->data.id == id)
        {
            return &list->data;
        }
        else 
        return NULL;
    }
}
#endif

int list_destory(struct node_st * me)
{
    struct node_st * list;

    if(me == NULL)
        return 0;
    
    for(list = me; list != NULL; list = me)
    {
        list = me -> next;
        free(me);
    }
    return 0;
}