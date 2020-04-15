/*
 * @Author       : fieldxy
 * @Date         : 2020-04-11 16:39:17
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-15 12:00:32
 * @Description  : In User Settings Edit
 * @FilePath     : /root/MyGit/apue/ds/line/list/linklist/simple/head/main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    list * l;
    int i;
    datatype arr[] = {11, 22, 33, 44};
    l = list_creat();
    if(l == NULL)
        exit(1);

    printf("%d\n",__LINE__);

    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++){
        if(list_insert_at(l,0,&arr[i])){
            printf("%d\n",__LINE__);
            exit(1);
        }
    }

    printf("%d\n",__LINE__);

    list_display(l);
    printf("%d\n",__LINE__);
    list_destroy(l);
    exit(0);
}