/*
 * @Author       : fieldxy
 * @Date         : 2020-05-05 18:53:29
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-05 18:57:31
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/ball_clock/queue.h
 */

#ifndef QUEUE_H__
#define QUEUE_H__

typedef int datatype;

#define MAXSIZE     32

typedef struct node_st
{
    datatype data[MAXSIZE];
    int head;
    int tail;
}queue;

queue *qu_create();

int qu_isempty(queue *);

int qu_enqueue(queue *,datatype *data);

int qu_dequeue(queue *, datatype *);

void qu_travel(queue *);

void qu_clear(queue *);

void qu_destory(queue *);

#endif
