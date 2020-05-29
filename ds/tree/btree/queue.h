/*
 * @Author       : fieldxy
 * @Date         : 2020-05-03 20:58:13
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-03 22:46:55
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\ds\line\squeue\list\queue.h
 */
#ifndef QUEUE_H__
#define QUEUE_H__

#include "llist.h"

typedef LLIST  QUEUE;

QUEUE *queue_create(int );

int queue_en(QUEUE *,const void *);

int queue_de(QUEUE *,void *);

void queue_destory(QUEUE *);


#endif