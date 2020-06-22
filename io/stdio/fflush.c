/*
 * @Author       : fieldxy
 * @Date         : 2020-03-12 21:23:25
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-03-13 10:19:50
 * @Description  : In User Settings Edit>
 * @FilePath     : /linux_c/stdio/io/fflush.c
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i;

/**
 *  printf("Before While()\n");

    while(1);

    printf("After While()\n");
***/

    printf("Before While()");
    fflush(stdout);

    while(1);

    printf("After While()");
    fflush(NULL);
    
    exit(0);
}