/*
 * @Author       : fieldxy
 * @Date         : 2020-04-29 07:52:00
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-01 11:37:28
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/double/lib3/llist.h
 */
#ifndef LLIST_H__
#define LLIST_H__

#define LLIST_FORWARD   1
#define LLIST_BACKWARE  2

typedef void llist_op(const void *);
typedef int llist_cmp(const void *,const void *);

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

typedef struct llist_head
{
    int size;
    struct llist_node_st head;
    int (*insert)(struct llist_head *,const void *,int );
    void  *(*find)(struct llist_head *,const void *,llist_cmp *);
    int (*delete)(struct llist_head *, const void *,llist_cmp *);
    int (*fetch)(struct llist_head *,const void *key, llist_cmp *,void *data);
    void (*travel)(struct llist_head *, llist_op *);
}LLIST;


LLIST * llist_creat(int initsize);
void llist_destory(LLIST *);



#endif