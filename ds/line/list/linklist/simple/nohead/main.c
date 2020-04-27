/*
 * @Author       : fieldxy
 * @Date         : 2020-04-26 15:31:54
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-27 22:43:46
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

    int id = 3;
    struct score_st *ptr;
    ptr = list_fine(list,id);
    if(ptr == NULL)
        printf("con not find!\n");
    else
        printf("%d %s %d %d",ptr->id,ptr->name,ptr->math,ptr->chinese);

    list_destory(list);

#if 0    
    list_delete(&list);
    list_display(list);
#endif
    exit(0);
}


