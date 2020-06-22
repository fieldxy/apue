/*
 * @Author       : fieldxy
 * @Date         : 2020-04-09 20:38:11
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-10 21:36:42
 * @Description  : sqlist 
 * @FilePath     : /root/MyGit/apue/ds/line/list/arr/sqlist.h
 */
#ifndef SQLIST_H__
#define SQLIST_H__

#define DATASIZE    1024

typedef int datatype;

typedef struct node_st
{
    datatype data[DATASIZE];
    int last;
}sqlist;

sqlist * sqlist_create();

int sqlist_create1(sqlist **);

int sqlist_insert(sqlist *,int i,datatype * );

int sqlist_delete(sqlist *, int i);

int sqlist_find(const sqlist * me,const datatype * data);

int sqlist_isempty(sqlist *);

int sqlist_setempty(sqlist *);

int sqlist_getnum(sqlist *);

int sqlist_display(sqlist *);

int sqlist_destroy(sqlist *);

int sqlist_union(sqlist *,sqlist *);
#endif
