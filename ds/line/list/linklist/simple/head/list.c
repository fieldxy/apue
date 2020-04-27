/*
 * @Author       : fieldxy
 * @Date         : 2020-04-11 16:39:04
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-16 18:19:28
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\ds\line\list\linklist\simple\head\list.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list *list_creat()
{
    list * me;
    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;
    me->next = NULL;
    return me;
}


int list_insert_at(list *me,int i,datatype *data)
{
    int j = 0;
    list * node = me;
    list * newnode;

    if( i < 0)
        return -1;

    while((j < i) && (node != NULL)){
        node = node->next;
        j++;
    }

    if(j == 0){
        newnode = malloc(sizeof(*newnode));
        if(newnode == NULL)
            return -2;
        newnode ->data = *data;
        newnode ->next = node->next;
    }

    if(node != NULL){
        newnode = malloc(sizeof(*newnode));
        if(newnode == NULL)
            return -2; 
        newnode ->data = *data;   
        newnode ->next = node->next;
        node->next =  newnode;  
        return 0;
    }
    else 
        return -3;

}

int list_order_insert(list *me,datatype *data)
{
    list *p = me, *q;
    while (p->next && p->next->data < *data)
        p = p->next;

    q = malloc(sizeof(*p));
    if(q == NULL)
        return -1;
    
    q->data = *data;
    q->next = p->next;
    p->next = q;

    return 0;
    
}

int list_delete_at(list *me, int i, datatype *data)
{
    list * p = me, *q;
    *data = -1;
    int j = 0;
    while (j < i && p)
    {
        p = p->next;
        j++;
    }

    if(p->next == NULL)
        return -2;
    q = p->next;
    p->next = q->next;
    *data = q->data;
    free(q);
    q = NULL;
    
    return 0;
}

int list_delete(list *me,datatype *data)
{
    list * p = me, *q;

    while(p->next && p->next->data != *data)
        p = p->next;
    
    if(p->next == NULL)
        return -1;
    q = p->next;
    p->next = q->next;
    free(q);
    q = NULL;
    return 0;
}

int list_isempty(list *me)
{
    if(me ->next == NULL)
        return 0;
    else
        return 1;
}

int list_display(list *me)
{
    list * node = me;
    if(list_isempty(me) == 0)
        return 0;
    node = node ->next;
    while (node != NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
    return 0;  
}

void list_destroy(list *me)
{
    list *node;
    for(node = me->next; node!= NULL; node = node->next){
        node = node->next;
        free(node);
    }
    free(me);
    return;
}