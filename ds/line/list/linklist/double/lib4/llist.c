/*
 * @Author       : fieldxy
 * @Date         : 2020-04-29 07:52:00
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-01 11:52:54
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/double/lib4/llist.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

#define new_list
#ifndef new_list
struct llist_node_st
{
    void * data;
    struct llist_node_st *prev;
    struct llist_node_st *next;
};

#else /*使用变长结构体*/
   
struct llist_node_st
{
    struct llist_node_st *prev;
    struct llist_node_st *next;
    char data[0]; /*C99支持数组为0*/
};

#endif

struct llist_head_st
{
    int size;
    struct llist_node_st head;
    int (*insert)(struct llist_head *,const void *,int );
    void  *(*find)(struct llist_head *,const void *,llist_cmp *);
    int (*delete)(struct llist_head *, const void *,llist_cmp *);
    int (*fetch)(struct llist_head *,const void *key, llist_cmp *,void *data);
    void (*travel)(struct llist_head *, llist_op *);
};


LLIST * llist_creat(int initsize)
{
    struct llist_head_st * new;
    new = malloc(sizeof(*new));
    if(new == NULL)
        return NULL;
    
    new->size = initsize;
    new->head.prev = &new->head;
    new->head.next = &new->head;

    new->insert = llist_insert;
    new->delete = llist_delete;
    new->find = llist_find;
    new->fetch = llist_fetch;
    new->travel = llist_travel;

    return new;
}

int llist_insert(LLIST *p,const void *data,int mode)
{
    struct llist_node_st *newnode;
    struct llist_head_st *ptr = p;
    newnode = malloc(sizeof(*newnode) + ptr->size);
    if(newnode == NULL)
        return -1;

    memcpy(newnode->data,data,ptr->size);

    /*首部插入*/
    if(mode == LLIST_FORWARD)
    {
        newnode ->prev = &ptr->head;
        newnode ->next = ptr->head.next;
    }
    else
    if(mode == LLIST_BACKWARE) /*尾部插入*/
    {
        newnode ->prev = ptr->head.prev;
        newnode ->next = &ptr->head;
    }
    else    /*error*/
    {
        return -3;
    }

    newnode ->prev->next = newnode;
    newnode ->next->prev = newnode;

    return 0;

}

static struct llist_node_st *  find_(struct llist_head_st *p,const void *key, llist_cmp *cmp)
{
    struct llist_node_st *cur;
    struct llist_head_st *ptr = p;
    for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        if(cmp(key,cur->data) == 0)
            break;
    }

    return cur;
}

void *llist_find(LLIST *p,const void *key,llist_cmp *cmp)
{
    struct llist_node_st *node;
    struct llist_head_st *ptr = p;
    node =  find_(ptr,key,cmp);
    if(node == &ptr->head)
        return NULL;

    return node->data;
}

int llist_delete(LLIST *p,const void *key,llist_cmp *cmp)
{
    struct llist_node_st *node;
    struct llist_head_st *ptr = p;
    node = find_(ptr,key,cmp);
    if(node == &ptr->head)
        return -1;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return 0;
}

int llist_fetch(LLIST *p,const void *key, llist_cmp *cmp,void *data)
{
    struct llist_node_st *node;
    struct llist_head_st *ptr = p;
    node = find_(ptr,key,cmp);
    if(node == &ptr->head)
        return -1;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if(data != NULL)
        memcpy(data,node->data,ptr->size);
    free(node);
}

void llist_travel(LLIST * p,llist_op *op)
{
    struct llist_node_st *cur;
    struct llist_head_st *ptr = p;
    for(cur = ptr->head.next; cur!=&ptr->head; cur = cur->next)
        op(cur->data);

}

void llist_destory(LLIST * p)
{
    struct llist_node_st *cur,*next;
    struct llist_head_st *ptr = p;
    for(cur = ptr->head.next; cur != &ptr->head; cur = next->next)
    {
        next = cur->next;
        free(cur);
    }
}


