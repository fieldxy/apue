/*
 * @Author       : fieldxy
 * @Date         : 2020-05-30 11:42:30
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-30 13:49:33
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\ds\tree\trie\trie.c
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESC_SIZE   256
#define KEY_SIZE    256
#define BUFSIZE     512
#define FNAME       "log"
struct node_st 
{
    struct node_st *ch[26];
    char desc[DESC_SIZE];
};

int get_word(FILE *fp, char *key, char *desc)
{
    char buf[BUFSIZE];
    char *retp;
    int i,j;
    // while (1)
    // {
        retp = fgets(buf,BUFSIZE,fp);
        if(retp == NULL)
            return -1;    
    // }
    for(i = 0; i < KEY_SIZE - 1 && buf[i] != ':'; i++)
        key[i] = buf[i];
        
    key[i] = '\0';

    i++;

    for(j = 0; j < DESC_SIZE - 1 && buf[i] != '\0';j++,i++)
        desc[j] =buf[i];

    return 0;
}
struct node_st *newnode(void)
{
    struct node_st *node;
    node = malloc(sizeof(*node));
    if(node == NULL)
        return NULL;
    
    node->desc[0] = '\0';
    for(int i= 0; i < 26; i ++)
        node->ch[i] = NULL;
}


int insert(struct node_st **root,char *key,char *desc)
{
    if(*root == NULL)
    {
        *root = newnode();
        if(*root == NULL)
            return -1;
    }

    if(*key == '\0')
    {
        strcpy((*root)->desc,desc);
        return 0;
    }

    insert((*root)->ch+ *key - 'a',key+1,desc);
}

int main()
{
    struct node_st *tree;
    FILE *fp;
    char desc[DESC_SIZE] = {'\0'},key[KEY_SIZE] = {'\0'};
    int ret;
    
    fp = fopen(FNAME,"r");
    if(fp == NULL)
    {
        fprintf(stderr,"fopen():error!\n");
        exit(1);
    }

    while(1)
    {
        ret = get_word(fp,key,desc);
        if(ret == -1 )
            break;
        insert(&tree,key,desc);
    }

    fclose(fp);

    exit(0);
}