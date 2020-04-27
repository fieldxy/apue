/*
 * @Author       : fieldxy
 * @Date         : 2020-04-26 15:31:49
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-27 21:42:12
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/simple/nohead/list.h
 */
#ifndef LIST_H_
#define LIST_H_

#define NAMESIZE 1024

typedef int datatype;

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

typedef struct node_st
{
    struct score_st data;
    struct node_st *next;
}list;

list *list_creat();
#if 0
struct node_st *  list_insert(struct node_st *,struct score_st *data);
#else
int list_insert(struct node_st **,struct score_st *data);
#endif
int list_display(struct node_st *me);




#endif