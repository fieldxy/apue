/*
 * @Author       : fieldxy
 * @Date         : 2020-04-29 07:52:00
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-30 07:21:03
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/double/lib1/llist.h
 */
#ifndef LLIST_H__
#define LLIST_H__

#define LLIST_FORWARD   1
#define LLIST_BACKWARE  2

typedef void llist_op(const void *);
typedef int llist_cmp(const void *,const void *);
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

void *llist_find(LLIST *ptr,const void *key,llist_cmp *cmp);

int llist_delete(LLIST *ptr,const void *key,llist_cmp *cmp);

int llist_fetch(LLIST *,const void *key, llist_cmp *,void *data);

void llist_travel(LLIST * ,llist_op * op);

void llist_destory(LLIST *);



#endif