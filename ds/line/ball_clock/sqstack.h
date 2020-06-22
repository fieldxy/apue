/*
 * @Author       : fieldxy
 * @Date         : 2020-05-05 18:53:00
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-05 19:10:54
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/ball_clock/sqstack.h
 */
#ifndef SQSTACK_H__
#define SQSTACK_H__

#define SIZE     32
typedef int         type;

typedef struct 
{
    type data[SIZE]; /*数据*/
    int top;                /*top 记录栈顶的位置 */
}sqstack;

/*创建一个顺序存储的栈*/
sqstack *st_create(void);

/**/
int st_isempty(sqstack *);

int st_push(sqstack *,type *);

int st_pop(sqstack *,type *);

int st_top(sqstack *,type *);

void st_travel(sqstack *);

void st_destory(sqstack *);
#endif