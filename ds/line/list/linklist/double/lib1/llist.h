/*
 * @Author       : fieldxy
 * @Date         : 2020-04-29 07:52:00
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-29 08:18:17
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/double/lib1/llist.h
 */
#ifndef LLIST_H__
#define LLIST_H__

#define LLIST_FORWARD   1
#define LLIST_BACKWARE  2

struct llist_node_st
{
    void * data;
    struct llist_node_st *prev;
    struct llist_node_st *next;
};

typedef struct 
{
    int size;
    struct llist_node_st head;
}LLIST;

LLIST * llist_creat(int initsize);

int llist_insert(LLIST *,const void *data,int mode);

llist_find();

llist_delete();

llist_fetch();

void llist_travel(LLIST *);

void llist_destory(LLIST *);



#endif