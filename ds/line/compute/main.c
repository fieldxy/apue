/*
 * @Author       : fieldxy
 * @Date         : 2020-05-04 10:37:54
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-05 17:54:11
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/compute/main.c
 */
#include "sqstack.h"
#include <stdio.h>
#include <stdlib.h>

static void compute(sqstack *snum,datatype * sop)
{
    datatype n1,n2;
    datatype n;
    st_pop(snum,&n2); /*注意 / */
    st_pop(snum,&n1);

    switch (*sop)
    {
    case '+':
        n = n1 + n2;
        break;
    case '-':
        n = n1 - n2;
        break;
    case '*':
        n = n1 * n2;
        break;
    case '/':
        n = n1 / n2;
        break;
    default:
        exit(1);
    }

    st_push(snum,&n);
}


static void deal_bracket(sqstack *snum,sqstack *sop)
{
    datatype old_op;
#if 1    
    st_top(sop,&old_op);
    while (old_op != '(')
    {

        st_pop(sop,&old_op);
        compute(snum,&old_op);
        st_pop(sop,&old_op);
    }
        // st_pop(sop,&old_op);
#else
    
    st_pop(sop,&old_op);
    compute(snum,&old_op);
#endif
}

static int get_pri(int op)
{
    switch (op)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
}

static void deal_op(sqstack *snum,sqstack *sop,int op)
{
    datatype old_op;
    if(st_isempty(sop) || op == '(')
    {
        st_push(sop,&op);
        st_travel(sop);
        return ;
    }
    
    st_pop(sop,&old_op);

    if(get_pri(op) > get_pri(old_op))
    {
        st_push(sop,&old_op);
        st_push(sop,&op);
        return ;
    }
    
    while(get_pri(op) <= get_pri(old_op))
    {
        compute(snum,&old_op);
        if(st_isempty(sop))
            break;
        st_pop(sop,&old_op);
    }
    
    st_push(sop,&op);
    
}

int main()
{
    int i = 0;
    char str[]="(11+2)*2-5";
    int value = 0 ;
    int flag = 0;
    datatype old_op;
    sqstack *snum,*sop;

    snum = st_create();
    if(snum == NULL)
        exit(1);
    
    sop = st_create();
    if(sop == NULL)
        exit(1);
    while (str[i] != '\0')  
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            value = value  * 10 + (str[i] - '0');
            flag = 1; 
        }else
        {
            if(flag)
            {
                st_push(snum,&value);
                flag = 0;
                value = 0;
            }
            if(str[i] == ')')
            {
                deal_bracket(snum,sop);
            }else /* + - * / */
            {
                deal_op(snum,sop,str[i]);
            }
        }
        i++;
    }

    if(flag)
        st_push(snum,&value);

    while(!st_isempty(sop))
    {
        st_pop(sop,&old_op);
        compute(snum,&old_op);
    }
    st_pop(snum,&value);
    printf("%s: %d\n",str,value);
    st_destory(snum);
    st_destory(sop);

    exit(0);
}