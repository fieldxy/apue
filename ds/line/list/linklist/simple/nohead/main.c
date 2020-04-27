/*
 * @Author       : fieldxy
 * @Date         : 2020-04-26 15:31:54
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-27 21:43:48
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/simple/nohead/main.c
 */
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main()
{
    int i;
    struct node_st *list = NULL;
    struct score_st tmp;
    for(i = 0; i < 7; i++){
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"stu%d",i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        if(list_insert(&list,&tmp) < 0)
            exit(1);
    }
    list_display(list);
    
    exit(0);
}


