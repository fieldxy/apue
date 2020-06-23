/*
 * @Author       : field
 * @Date         : 2020-06-22 20:02:15
 * @LastEditors  : field
 * @LastEditTime : 2020-06-22 20:44:30
 * @Description  : file content
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void alrm_handler(int s)
{
    alarm(1);
    printf("Get SIGALRM\n");
}

int main()
{
    int ch;
    signal(SIGALRM, alrm_handler);
    alarm(1);

    while (1)
    {
        // printf("this is while(1)\n");
        // sleep(1);
        ch = getchar();
        // if(ch == 'Q')
        //     break;
        printf("ch = %x\n ",ch);
        // fflush(NULL);
    }
    
    return 0;
}




