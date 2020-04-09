/*
 * @Author       : fieldxy
 * @Date         : 2020-04-08 16:37:46
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-08 16:46:32
 * @Description  : union 学习
 * @FilePath     : /root/MyGit/apue/struct_union/union.c
 */
 #include <stdio.h>
 #include <stdlib.h>

union test_un{
    int i;
    float f;
    // double d;
    char ch;
};

 int main()
 {
    union test_un a;
    union test_un *p;
    p = &a;
    a.f = 345.678;
    printf("%f\n",a.f);
    printf("%d\n",sizeof(a));
    exit(0);
 }