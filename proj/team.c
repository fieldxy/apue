/*
 * @Author: field
 * @Date: 2020-06-12 17:08:28
 * @LastEditors: field
 * @LastEditTime: 2020-06-12 19:09:34
 * @Description: file content
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <stdio.h>
#include <

int main()
{
    char ch;
    struct termios new;
    tcgetattr(,&new);
    new.
    tcsetattr(0,TCSANOW,&new);
    
    while (1)
    {
        ch = getchar();
        printf("%x ",ch);
        fflush(NULL);
    }
    


    exit(0);
}