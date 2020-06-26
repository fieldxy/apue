/*
 * @Author       : field
 * @Date         : 2020-06-25 16:58:29
 * @LastEditors  : field
 * @LastEditTime : 2020-06-25 23:27:01
 * @Description  : file content
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    int count = 0;
    FILE *fp = NULL;

    while (1)
    {
        fp = fopen("tmp","r");
        
        if(fp == NULL)
        {
            // fprintf(stderr,"fopen() failed ! errno = %d\n",errno);
            perror("fopen()");
            // fprintf(stderr, "fopen():%s\n",strerror(errno)); /* 不包含string.h 会发生段错误*/
            break;
        }
        count ++;
    }

    printf("count = %d \n",count);
    // puts("OK!");
    
    exit(0);
}