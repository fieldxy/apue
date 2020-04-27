/*
 * @Author       : fieldxy
 * @Date         : 2020-03-11 21:33:35
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-03-11 21:52:38
 * @Description  : fgetc.c
 * @FilePath     : /linux_c/stdio/io/fgetc.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <error.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int count = 0;
    if(argc < 2){
        fprintf(stderr,"Usage...\n");
        exit(1);
    }

    fp = fopen(argv[1],"r");
    if(fp == NULL){
        perror("fopen()");
        exit(1);
    }

    while (fgetc(fp) != EOF)
    {
        count++;
    }
    
    printf("count = %d\n",count);

    fclose(fp); 

    exit(0);
}