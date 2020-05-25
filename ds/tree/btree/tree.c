/*
 * @Author       : fieldxy
 * @Date         : 2020-05-06 12:54:07
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-25 11:56:19
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
#if 1
    int tmpid = 12;
    datap = find(tree,tmpid);
    if(datap == NULL)
        printf("cant not find this id %d !\n",tmpid);
    else
        print_s(datap);
#endif
    draw(tree);

    balance(&tree);
    
    draw(tree);
    
    exit(1);
   
}