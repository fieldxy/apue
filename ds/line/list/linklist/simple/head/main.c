/*
 * @Author       : fieldxy
 * @Date         : 2020-04-11 16:39:17
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-16 18:21:54
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\ds\line\list\linklist\simple\head\main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    list * l;
    int i;
    datatype a = 89;
    datatype value;
    datatype arr[] = {11, 22, 55, 66, 89, 33, 44};
    l = list_creat();
    if(l == NULL)
        exit(1);
#if 0   /*按data大小插入链中*/
    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++){
        if(list_order_insert(l,&arr[i]) != 0)
            exit(1);
    }

    list_display(l);
#endif
    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
        if(list_insert_at(l,0,&arr[i]) != 0)
            exit(1);
    

    list_display(l);
    list_delete_at(l,1,&value);
    printf("value = %d\n",value);
    list_display(l);
    list_delete(l,&a);
    list_display(l);
    list_destroy(l);
    exit(0);
}