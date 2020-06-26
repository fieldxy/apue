/*
 * @Author       : field
 * @Date         : 2020-06-25 16:58:29
 * @LastEditors  : field
 * @LastEditTime : 2020-06-25 22:29:39
 * @Description  : file content
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE *fp;

    fp = fopen("tmp","r");

    if(fp == NULL)
    {
        // fprintf(stderr,"fopen() failed ! errno = %d\n",errno);
        // perror("fopen()");
        fprintf(stderr, "fopen():%s\n",strerror(errno)); /* 不包含string.h 会发生段错误*/
        exit(1);
    }
    puts("OK!");
    
    exit(0);
}