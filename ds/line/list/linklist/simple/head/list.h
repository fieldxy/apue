/*
 * @Author       : fieldxy
 * @Date         : 2020-04-11 16:39:12
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-16 18:04:17
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\ds\line\list\linklist\simple\head\list.h
 */
#ifndef LIST_H__
#define LIST_H__

typedef int datatype;

typedef struct node_st
{
    datatype data;
    struct node_st *next;
}list;

list *list_creat();

int list_insert_at(list *,int i,datatype *);

int list_order_insert(list *,datatype *);

int list_delete_at(list *, int i, datatype *);

int list_delete(list *,datatype *);

int list_isempty(list *);

int list_display(list *me);

void list_destroy(list *);





#endif