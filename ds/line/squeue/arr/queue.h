/*
 * @Author       : fieldxy
 * @Date         : 2020-05-03 17:51:25
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-03 19:05:10
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/squeue/arr/queue.h
 */

#ifndef QUEUE_H__
#define QUEUE_H__

typedef int datatype;

#define MAXSIZE     64

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
