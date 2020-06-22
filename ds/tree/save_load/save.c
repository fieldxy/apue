/*
 * @Author       : fieldxy
 * @Date         : 2020-05-06 12:54:07
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-29 10:54:17
 * @Description  : 将数以广义表的形式存储
 * @FilePath     : \apue\ds\tree\save_load\save.c
 */
#include <stdio.h>
#include <stdlib.h>

#define FNAME "/tmp/out"

struct node_st
{
    char data;
    struct node_st *light;
    struct node_st *right;
};

static struct node_st *tree = NULL;

int insert(struct node_st **root,int data)
{
    struct node_st *node;
    if(*root == NULL)
    {
        node = malloc(sizeof(*node));
        if(node == NULL)
            return -1;
        node->data = data;
        node->light = NULL;
        node->right = NULL;

        *root = node;
        return 0;
    }
    if(data  <= (*root)->data)
        return insert(&(*root)->light,data);
    return insert(&(*root)->right,data);
}

void draw_(struct node_st * root,int level)
{
    if(root == NULL)
        return;
    draw_(root->right,level + 1 );
    for(int i=0; i < level ; i++)
        printf("    ");
    printf("%c \n",root->data);

    draw_(root->light,level + 1 );
    
}

void draw(struct node_st *root)
{
    draw_(root,0);
    printf("\n\n");
}

int save_(struct node_st *root,FILE *fp)
{
    fputc('(',fp);
    if(root == NULL)
    {
        fputc(')',fp);
        return 0;
    }    
        
    fputc(root->data,fp);
    
    save_(root->light,fp);
    save_(root->right,fp);

    fputc(')',fp);
    return 0;
}

int save(struct node_st *root,const char *path)
{
    FILE *fp;
    fp = fopen(path,"w");
    if(fp == NULL)
        return -1;
    save_(tree,fp);
    return 0;
}




int main()
{
    char arr[] = "cefadjbh";
    
    for(int i = 0; i< sizeof(arr)/sizeof(*arr) - 1; i++){
        insert(&tree,arr[i]);
    }
    draw(tree);
    
    save(tree,FNAME);

    exit(1);
   
}