/*
 * @Author       : field
 * @Date         : 2020-06-30 17:59:48
 * @LastEditors  : field
 * @LastEditTime : 2020-06-30 18:03:49
 * @Description  : file content
 * @FilePath     : /apue/io/sys/ctr_fl.c
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void set_fl(int fd, int flags)
{
    int val;
    
    if((val = fcntl(fd, F_GETFL, 0)) < 0)
        perror("fcntl()");
    
    val |= flags;

    if(fcntl(fd, F_SETFL, val) < 0)
        perror("fcntl()");
}

void clr_fl(int fd, int flags)
{
    int val;
    
    if((val = fcntl(fd, F_GETFL, 0)) < 0)
        perror("fcntl()");
    
    val &= ~flags;

    if(fcntl(fd, F_SETFL, val) < 0)
        perror("fcntl()");
}
