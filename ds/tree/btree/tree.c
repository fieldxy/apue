/*
 * @Author       : fieldxy
 * @Date         : 2020-05-06 12:54:07
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-08 21:27:43
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\ds\tree\btree\tree.c
 */
#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};


struct node_st
{
    struct score_st data;
    struct node_st *light;
    struct node_st *right;
};


intsert(struct node_st **root,struct score_st *data)
{
    struct node_st *node;
    if(*root == NULL)
    {
        node = malloc(sizeof(*node));
    }
    if(data ->id <= (*root)->data.id)
        (*root)->right;
    else
    {
        (*root)
    }
    
}

int main()
{
    int arr[] = {1,2,3,7,8,9,4,5};
    struct node_st *tree = NULL;
    struct score_st tmp;
    
    for(int i = 0; i< sizeof(arr)/sizeof(*arr); i++){
        tmp.id = arr[i];
        snprintf(tmp.name,NAMESIZE,"std%d",i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        
        insert(&tree,&tmp);
    }


    
    exit(1);
}