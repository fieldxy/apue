/*
 * @Author       : field
 * @Date         : 2020-06-30 14:05:18
 * @LastEditors  : field
 * @LastEditTime : 2020-06-30 14:17:39
 * @Description  : file content
 * @FilePath     : /apue/io/sys/hole.c
 */ 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;

    // if((fd = creat("file.hole", FILE_MODE)) < 0)
    if((fd = open("file.hole", O_WRONLY| O_CREAT| O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
        perror("creat()");
    
    if(write(fd, buf1, 10) != 10)
        perror("write()");
    /*offset now = 10*/
    
    if(lseek(fd, 16384, SEEK_SET) == -1) 
        perror("lseek()");

    if(write(fd, buf2, 10) != 10)
        perror("write()");
    /*offset now = 16394*/
    
    exit(0);
}
