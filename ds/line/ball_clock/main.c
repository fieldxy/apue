/*
 * @Author       : fieldxy
 * @Date         : 2020-05-05 18:59:18
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-05 19:34:48
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/ball_clock/main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "sqstack.h"

#define NR_BALL     27

static int check(queue * qu)
{
    int i = (qu->head + 1)%MAXSIZE;
    
    while(i != qu->tail)
    {
        if(qu->data[i] > qu->data[(i+1) % MAXSIZE])
            return 0;
            i = (i + 1)%MAXSIZE;
    }
    return 1;
}

int main()
{
    int t;

    queue * qu;
    qu = qu_create();
    if(qu == NULL)
        exit(1);
    sqstack *st_hour, *st_fivemin, *st_min;
    st_hour = st_create();
    st_fivemin = st_create();
    st_min = st_create();
    if(st_hour == NULL ||st_fivemin == NULL || st_min == NULL)
        exit(1);

    for(int i = 1; i <= NR_BALL; i++)
        qu_enqueue(qu,&i);

    qu_travel(qu);
    int time,value;
    while(1)
    {
        qu_dequeue(qu,&t);
        time ++;
        if(st_min->top != 3)
        {
            st_push(st_min,&t);   
        }else
        {
            while(!st_isempty(st_min))
            {
                st_pop(st_min,&value);
                qu_enqueue(qu,&value);
            }
            
            if(st_fivemin->top != 10)
                st_push(st_fivemin,&t);
            else
            {
                while(!st_isempty(st_fivemin))
                {
                    st_pop(st_fivemin,&value);
                    qu_enqueue(qu,&value);
                }
                if(st_hour->top != 10)
                    st_push(st_hour,&t);
                else
                {
                    while(!st_isempty(st_hour))
                    {
                        st_pop(st_hour,&value);
                        qu_enqueue(qu,&value);
                    }
                    qu_enqueue(qu,&t);
                    qu_travel(qu);
                    if(check(qu))
                        break;
                }
            }
        }
    }
    
    printf("time = %d\n",time);
    qu_destory(qu);
    st_destory(st_hour);
    st_destory(st_fivemin);
    st_destory(st_min);


    exit(0);
}