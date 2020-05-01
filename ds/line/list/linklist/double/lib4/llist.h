/*
 * @Author       : fieldxy
 * @Date         : 2020-04-29 07:52:00
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-01 12:02:04
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/double/lib4/llist.h
 */
#ifndef LLIST_H__
#define LLIST_H__

typedef void LLIST;

#define LLIST_FORWARD   1
#define LLIST_BACKWARE  2

typedef void llist_op(const void *);
typedef int llist_cmp(const void *,const void *);



LLIST * llist_creat(int initsize);
int llist_insert(LLIST *,const void *data,int mode);
void *llist_find(LLIST *,const void *key,llist_cmp *cmp);
int llist_delete(LLIST *,const void *key,llist_cmp *cmp);
int llist_fetch(LLIST *,const void *key, llist_cmp *,void *data);
void llist_travel(LLIST * ,llist_op * op);
void llist_destory(LLIST *); 



#endif