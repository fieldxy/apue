/*
 * @Author       : fieldxy
 * @Date         : 2020-05-03 17:51:13
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-03 19:09:54
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/squeue/arr/main.c
 */
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    queue *sq;
    datatype arr[] = {1,2,3,4,5,6,7,8};

    sq = qu_create();
    if(sq == NULL)
        exit(1);

    for(int i = 0; i < sizeof(arr) / sizeof(*arr) ; i ++)
        qu_enqueue(sq,&arr[i]);    
    
    qu_travel(sq);

    for(int i = 0; i < sizeof(arr) / sizeof(*arr) ; i ++)
        qu_enqueue(sq,&arr[i]);
        
    qu_travel(sq);
    
    datatype tmp;
    while (sq->head != sq->tail)    
    {
        qu_dequeue(sq,&tmp);
        printf("%d \n",tmp);
        qu_travel(sq);
    }
    

    qu_destory(sq);

    exit(1);
}