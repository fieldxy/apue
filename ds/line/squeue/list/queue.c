/*
 * @Author       : fieldxy
 * @Date         : 2020-05-03 22:06:37
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-03 22:51:04
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\ds\line\squeue\list\queue.c
 */
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

QUEUE * queue_create(int size)
{
    return llist_creat(size);
}

int queue_en(QUEUE *ptr,const void *data)
{
    return llist_insert(ptr,data,LLIST_BACKWARE);
}

static int always_match(const void *p1,const void *p2)
{
    return 0;
}

int queue_de(QUEUE *ptr,void *data)
{
    return llist_fetch(ptr,(const void *)0,always_match,data);
}

void queue_destory(QUEUE * ptr)
{
    llist_destory(ptr);
}
