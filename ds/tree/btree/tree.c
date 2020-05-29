/*
 * @Author       : fieldxy
 * @Date         : 2020-05-06 12:54:07
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-29 10:02:20
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\ds\tree\btree\tree.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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


int insert(struct node_st **root,struct score_st *data)
{
    struct node_st *node;
    if(*root == NULL)
    {
        node = malloc(sizeof(*node));
        if(node == NULL)
            return -1;
        node->data = *data;
        node->light = NULL;
        node->right = NULL;

        *root = node;
        return 0;
    }
    if(data ->id <= (*root)->data.id)
        return insert(&(*root)->light,data);
    return insert(&(*root)->right,data);
}

struct score_st *find(struct node_st *root,int id)
{
    if(root == NULL)
        return NULL;
    
    if(id == root->data.id)
        return &root->data;
    
    if(id < root->data.id)
        return find(root->light,id);
    else
        return find(root->right,id);
}

void print_s(struct score_st *d)
{
    printf("%d %s %d %d\n",d->id,d->name,d->math,d->chinese);
}

void draw_(struct node_st * root,int level)
{
    if(root == NULL)
        return;
    draw_(root->right,level + 1 );
    for(int i=0; i < level ; i++)
        printf("    ");
    print_s(&root->data);

    draw_(root->light,level + 1 );
    
}

void draw(struct node_st *root)
{
    draw_(root,0);
    printf("\n\n");
    // getchar();
    
}
int get_num(struct node_st *root)
{
    int num;
    if(root == NULL)
        return 0;

    return get_num(root->right) + 1 +get_num(root->light);
       
}
static struct node_st * find_min(struct node_st *root)
{
    if(root->light ==NULL)
        return root;
    return find_min(root->light);
}
void turn_left(struct node_st **root)
{
    if(*root == NULL)
        return ;
    struct node_st *cur = *root;
    *root = cur ->right;
    cur->right = NULL;
    find_min(*root) ->light = cur;
    // draw(*root);
}
static struct node_st * find_max(struct node_st *root)
{
    if(root->light ==NULL)
        return root;
    return find_max(root->right);
}
void turn_right(struct node_st **root)
{
    if(*root == NULL)
        return ;
    struct node_st *cur = *root;
    *root = cur ->light;
    cur->light = NULL;
    find_max(*root) ->right = cur;
    // draw(*root);
}

void balance(struct node_st **root)
{
    int sub;
    if(*root == NULL)
        return ;
    while(1)
    {
        sub = get_num((*root) ->light) - get_num((*root)->right);
        // printf("%d %d %d\n",sub,get_num((*root)->light),get_num((*root)->right));
        if(sub >= -1 && sub <= 1)
            return ;
        if(sub < -1)
            turn_left(root);
        else
        {
            turn_right(root);
        }
    }
    balance(&(*root)->light);
    balance(&(*root)->right);

    
}
void delete(struct node_st **root,int id)
{
    struct node_st **node = root;
    struct node_st *cur =NULL;

    while(*node != NULL && (*node)->data.id != id)
    {
        if(id < (*node)->data.id)
            node = &(*node)->light;
        else
        {
            node = &(*node)->right;
        }
    }

    if(*node == NULL)
        return;
    
    cur = *node;

    if(cur->light == NULL)
        *node = cur->right;
    else
    {
        *node = cur->light;
        find_max(cur->light)->right = cur->right;
        
    }
    free(cur);
    
}
#if 0
void travel(struct node_st *root)
{
    if (root == NULL)
        return;
    print_s(&root->data);
    travel(root->light);
    travel(root->right);
    
}
#else
void travel(struct node_st *root)
{
    QUEUE *qu;
    struct node_st *cur;
    int ret;
    qu = queue_create(sizeof(struct node_st *));
    if(qu == NULL)
        return ;
    queue_en(qu,&root);
    /*if error*/
    while (1)
    {
        ret = queue_de(qu,&cur);
        if(ret == -1)
            break;
        print_s(&cur->data);

        if(cur->light != NULL)
            queue_en(qu,&cur->light);
        if(cur->right != NULL)
            queue_en(qu,&cur->right);
    }
    
    

}
#endif
int main()
{
    int arr[] = {1,2,3,7,8,9,4,5};
    struct node_st *tree = NULL;
    struct score_st tmp,*datap;
    
    for(int i = 0; i< sizeof(arr)/sizeof(*arr); i++){
        tmp.id = arr[i];
        snprintf(tmp.name,NAMESIZE,"std%d",i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        
        insert(&tree,&tmp);
    }
#if 0
    int tmpid = 12;
    datap = find(tree,tmpid);
    if(datap == NULL)
        printf("cant not find this id %d !\n",tmpid);
    else
        print_s(datap);
#endif
    travel(tree);
    draw(tree);

    balance(&tree);
    
    draw(tree);

    int tmpid = 5;
    delete(&tree,tmpid);
    draw(tree);
    travel(tree);
    exit(1);
   
}