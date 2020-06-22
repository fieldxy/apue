/*
 * @Author       : fieldxy
 * @Date         : 2020-06-05 18:00:42
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-06-05 18:21:01
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\proj\ansi_vt.c
 */ 
#include <stdlib.h>
#include <stdio.h>

int main()
{

    printf("\033[2J\033[1;1H\033[31;42;4mhello\n\033[0m");

    return 0;    

}