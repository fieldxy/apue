/*
 * @Author       : fieldxy
 * @Date         : 2020-04-09 20:37:59
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-10 23:20:35
 * @Description  : In User Settings Edit
 * @FilePath     : /root/MyGit/apue/ds/line/list/arr/main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

int main()
{
    int i,err;
    sqlist *list = NULL;
    sqlist *list1 = NULL;
    datatype arr[] = {12,13,14,55,66};
    datatype arr1[] = {23,45,6,4,323,12};
#if 1    
    list = sqlist_create();
#else
    sqlist_create1(&list);
#endif
    if(list == NULL){
        fprintf(stderr,"sqlist_create() failed!\n");
        exit(1);
    }


    for(i = 0; i <sizeof(arr)/sizeof(*arr); i++){
        if((err = sqlist_insert(list,0,&arr[i])) != 0){
            if(err == -1)
                fprintf(stderr,"The arr is full.");
            else if(err == -2)
                fprintf(stderr, "the pos you want to insert is worry");
            else 
                fprintf(stderr,"Error!\n");
        }
    }



    sqlist_display(list);

    list1 = sqlist_create();
    if(list1 == NULL){
        fprintf(stderr,"sqliat_creat() failed!\n");
        exit(1);
    }
// printf("%d me->last= %d\n",__LINE__,list->last);
    for(i = 0; i < sizeof(arr1)/sizeof(*arr1); i++)
        sqlist_insert(list1,0,&arr1[i]);
    sqlist_display(list1);

    sqlist_union(list,list1);

    sqlist_display(list);

    sqlist_destroy(list);
    sqlist_destroy(list1);


    exit(0);
}