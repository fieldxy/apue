/*
 * @Author       : fieldxy
 * @Date         : 2020-05-02 09:01:52
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-02 20:36:11
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/stack/arr/main.c
 */
#include "sqstack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    sqstack * st;
    datatype tmp;
    datatype arr[] = {1,2,3,4,5};
    
    st = st_create();

    for(int i=0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        st_push(st,&arr[i]);
    }
    
    st_travel(st);
    printf("%d \n",st->top);

    st_top(st,&tmp);

    printf("top=%d\n",tmp);

    for(int i = 0; i <= st->top; )
    {
        st_pop(st,&tmp);
        printf("top=%d\n",tmp);
        printf("POP:%d\n",tmp);
    }
#if 0
    datatype tmp = 6;
    st_push(st,&tmp);

    st_travel(st);
#endif
    st_destory(st);

    exit(0);
}