/*
 * @Author       : fieldxy
 * @Date         : 2020-04-03 22:48:49
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-04-03 23:03:19
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\point\point.c
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 1;
    int *p = &i;
    int **q = &p;



#if 0
    float *q;
    double *d;
    char *c;

    printf("%d\n",sizeof(p));
    printf("%d\n",sizeof(q));
    printf("%d\n",sizeof(d));
    printf("%d\n",sizeof(c));
#endif
#if 0
    p = &i;

    printf("%d\n",sizeof(i));
    printf("%d\n",sizeof(p));
    printf("i = %d\n",i);
    printf("&i = %p\n",&i);
    printf("p = %p\n",p);
    printf("&p = %p\n",&p);
    printf("*p = %d\n",*p);
#endif  

}