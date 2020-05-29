/*
 * @Author       : fieldxy
 * @Date         : 2020-05-06 12:54:07
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-29 11:45:33
 * @Description  : 解析广义表
 * @FilePath     : \apue\ds\tree\save_load\load.c
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


void draw_(struct node_st * root,int level)
{
    if(root == NULL)
        return;
    draw_(root->right,level + 1 );
    for(int i=0; i < level ; i++)
        printf("    ");
    printf("%c\n",root->data);

    draw_(root->light,level + 1 );
    
}

void draw(struct node_st *root)
{
    draw_(root,0);
    printf("\n\n");
}


struct node_st * load_(FILE *fp)
{
    int c;
    c = fgetc(fp);
    struct node_st *root;

    if(c != '(')
    {
        fprintf(stderr,"fgetc():error.\n");
        exit(1);
    }

    c = fgetc(fp);
    if(c == ')')
        return NULL;
    root = malloc(sizeof(*root));
    if(root == NULL)
        exit(1);
    root->data = c;
    root->light = load_(fp);
    root->right = load_(fp);
    fgetc(fp);
    return root;
    
}

struct node_st * load(const char *path)
{
    FILE *fp;
    struct node_st *root;

    fp = fopen(path,"r");
    if(fp == NULL)
        return NULL;
    
    root = load_(fp);
    
    fclose(fp);
    
    return root;
}


int main()
{
    struct node_st *root = load(FNAME);

    draw(root);

    exit(1);
   
}