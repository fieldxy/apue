/*
 * @Author       : fieldxy
 * @Date         : 2020-05-05 18:53:29
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-05 18:57:50
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/ball_clock/queue.c
 */


#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

/*创建一个循环队列*/
queue *qu_create()
{
    queue *sq;
    sq = malloc(sizeof(*sq));

    if(sq == NULL)
        return NULL;
    
    sq->head = 0;
    sq->tail = 0;

    return sq;
}

int qu_isempty(queue *sq)
{
    return (sq->head == sq->tail);
}

int qu_enqueue(queue *sq,datatype *data)
{
    if((sq->tail + 1) % MAXSIZE == sq->head)
        return -1;
    
    sq->tail = (sq->tail + 1) % MAXSIZE;
    sq->data[sq->tail] = *data; 
    return 0;
}

int qu_dequeue(queue *sq, datatype *data)
{
    if(qu_isempty(sq))
        return -1;
    sq->head = (sq->head + 1) % MAXSIZE;
    *data = sq->data[sq->head]; 
    return 0;
}

void qu_travel(queue *sq)
{
    if(sq->head == sq->tail)
        return;
    
    int i = (sq->head + 1) % MAXSIZE;
    while(i != sq->tail)
    {
        printf("%d ",sq->data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("%d \n",sq->data[i]);
}

void qu_clear(queue * sq)
{
    sq->head = sq->tail;
}

void qu_destory(queue *sq)
{
    free(sq);
}
