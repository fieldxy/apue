/*
 * @Author       : fieldxy
 * @Date         : 2020-04-28 08:03:42
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-28 08:40:22
 * @Description  : josephu
 * @FilePath     : /apue/ds/line/list/linklist/simple/josephu/jose.c
 */
#include <stdlib.h>
#include <stdio.h>

struct node_st
{
    int data;
    struct node_st * next;  
};

struct node_st * jose_creat(struct node_st *me)
{
    struct node_st *newnode,*cur;
    me = malloc(sizeof(*me));
    int i = 1;
    int n = 8;
    if(me == NULL)
        return NULL;
    me->data = i;
    me->next = me;
    i++;

    cur = me;

    for(;i <= n; i++)
    {
        newnode = malloc(sizeof(*newnode));
        if(newnode == NULL)
            return NULL;
        newnode ->data = i;
        newnode ->next = me;
        cur ->next = newnode;
        cur = newnode;
    }

    return me;
}

void jose_show(struct node_st * me)
{
    struct node_st *list = me;

    for(list = me;list->next != me;list=list->next)
    {
        printf("%d ",list->data);
    }
    printf("%d\n",list->data);
}

jose_kill(struct node_st *me, int n)
{
    struct node_st *cur = me,*node;
    int i = 1;

    while(cur != cur->next)
    {
        while(i < n)
        {
            node = cur;
            cur = cur->next;
            i++;
        }
        
        printf("%d ",cur->data);
        node->next = cur->next;
        free(cur);

        cur = node ->next;
        i = 1;
    }
    printf("\n",cur->data);

}
int main()
{
    struct node_st *list;

    int num = 8;
    int n = 3;
    list = jose_creat(list);
    
    jose_show(list);

    jose_kill(list,n);

    jose_show(list);

    exit(0);
}