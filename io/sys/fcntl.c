/*
 * @Author       : field
 * @Date         : 2020-06-30 17:35:48
 * @LastEditors  : field
 * @LastEditTime : 2020-06-30 17:54:58
 * @Description  : file content
 * @FilePath     : /apue/io/sys/fcntl.c
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv)
{
    int val;
    
    if(argc != 2)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }
    
    if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
        perror("fcntl()");
    printf("val = %x\n",val);
    switch (val & O_ACCMODE)
    {
    case O_RDONLY:
        printf("readly only");
        break;
    case O_WRONLY:
        printf("write only");
        break;
    case O_RDWR:
        printf("read write");
        break;  
    
    default:
        printf("unknown access mode\n");
        exit(1);
        break;
    }
    
    if(val & O_APPEND)
        printf(", append");
    
    if(val & O_NONBLOCK)
        printf(", nonblocking");
    
    if(val & O_SYNC)
        printf(", synchronous writes");
        
    #if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
        if(val & O_FSYNC)
            printf(", synchronous writes");
    #endif

    putchar('\n');
    exit(0);
}
