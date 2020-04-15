/*
 * @Author       : fieldxy
 * @Date         : 2020-04-11 16:39:04
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-15 11:58:56
 * @Description  : In User Settings Edit
 * @FilePath     : /root/MyGit/apue/ds/line/list/linklist/simple/head/list.c
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
    list * node;
    list * newnode;

    if( i < 0)
        return -1;

    while(j < i && node != NULL){
        node = node->next;
        j++;
    }

    if(node){
        newnode = malloc(sizeof(*newnode));
        if(newnode )
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

int list_delete_at(list *me, int i, datatype *data);

int list_delete(list *me,datatype *data);

int list_isempty(list *me)
{
    if(me ->next == NULL)
        return 0;
    else
        return 1;
}

int list_display(list *me)
{
    int i;
    list * node = me->next;
    if(list_isempty(me) == 0)
        return 0;
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