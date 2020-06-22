/*
 * @Author       : fieldxy
 * @Date         : 2020-03-22 23:15:39
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-03-23 08:19:52
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\fs\main.c
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i = 0;
    printf("argc = %d\n", argc);
    while(i < argc){
        printf("%s\n",argv[i]);
        i++;
    }


    exit(0);
}
