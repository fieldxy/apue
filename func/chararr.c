/*
 * @Author       : fieldxy
 * @Date         : 2020-04-07 23:51:27
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-08 00:08:29
 * @Description  : In User Settings Edit
 * @FilePath     : /root/MyGit/apue/func/chararr.c
 */
#include <stdio.h>
#include <stdlib.h>

char * mystrcpy(char * dest,const char * src)
{
    char *ret = dest;
    if(dest != NULL || src != NULL)
        while((* dest ++ = *src ++) != '\0');

    return ret;
}

char * mystrncpy(char * dest,const char * src,size_t n)
{
    int i;
    for(i = 0; i < n && (dest[i] = src[i]) ; i++)
    ;

    for( ; i < n; i++)
        dest[i] = '\0';

    return dest;
}

int main()
{
    char str1[] = "helloworld";
    char str2[128];

    // mystrcpy(str2,str1);
    mystrncpy(str2,str1,1);
    printf("%s\n",str2);

    return 0;
}