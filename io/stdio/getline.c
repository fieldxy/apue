/*
 * @Author       : fieldxy
 * @Date         : 2020-03-14 12:55:26
 * @LastEditors  : field
 * @LastEditTime : 2020-06-28 21:06:17
 * @Description  : In User Settings Edit
 * @FilePath     : /linux_c/apue/stdio/io/getline.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char *linebuf;
    size_t linesize;

    if(argc < 2){
        fprintf(stderr,"Usage....\n");
        exit(1);
    }

    fp = fopen(argv[1],"r+");
    if(fp == NULL){
        perror("fopen()");
        exit(1);
    }
    
    /**
     *  非常必须 会出现段错误
     *  内存泄漏
     */
    
    linebuf = NULL;
    linesize = 0;
    
    while (1)
    {
        if(getline(&linebuf,&linesize,fp) < 0)
            break;
        printf("%ld\n",strlen(linebuf));
        printf("%ld\n",linesize);
        
    }
    
    fclose(fp);
    //free(linebuf); //释放一块空间
    exit(0);
}