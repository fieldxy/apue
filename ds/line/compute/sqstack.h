/*
 * @Author       : fieldxy
 * @Date         : 2020-05-04 10:37:54
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-04 10:43:22
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/compute/sqstack.h
 */

#ifndef SQSTACK_H__
#define SQSTACK_H__

#define MAXSIZE     32
typedef int         datatype;

typedef struct node_st
{
    datatype data[MAXSIZE]; /*数据*/
    int top;                /*top 记录栈顶的位置 */
}sqstack;

/*创建一个顺序存储的栈*/
sqstack *st_create(void);

/**/
int st_isempty(sqstack *);

int st_push(sqstack *,datatype *);

int st_pop(sqstack *,datatype *);

int st_top(sqstack *,datatype *);

void st_travel(sqstack *);

void st_destory(sqstack *);
#endif