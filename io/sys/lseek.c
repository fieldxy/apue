/*
 * @Author       : field
 * @Date         : 2020-06-30 11:54:33
 * @LastEditors  : field
 * @LastEditTime : 2020-06-30 11:59:45
 * @Description  : file content
 * @FilePath     : /apue/io/sys/lseek.c
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
    
    exit(0);
}
