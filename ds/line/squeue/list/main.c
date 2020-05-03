/*
 * @Author       : fieldxy
 * @Date         : 2020-05-03 22:06:37
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-03 23:00:32
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\ds\line\squeue\list\main.c
 */
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

#define NAMESIZE    32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

void print_s(void * record)
{
    struct score_st *tmp = record;
    printf("%d %s %d %d\n",tmp->id,tmp->name,tmp->math,tmp->chinese);
}

int main()
{
    struct score_st tmp;
    QUEUE *qu;

    qu = queue_create(sizeof(struct score_st));

    for(int i = 0; i < 6 ; i ++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"stu%d",i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        if(queue_en(qu,&tmp) != 0)
            exit(1);        
    }

    while(1)
    {
        if(queue_de(qu,&tmp) == -1)
            break;
            print_s(&tmp);
    }

    queue_destory(qu);
    
    exit(0);

}