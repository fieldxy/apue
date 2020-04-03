#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 1;
    int *p;
    p = &i;

    printf("i = %d\n",i);
    printf("&i = %p\n",&i);
    printf("p = %p\n",p);
    printf("&p = %p\n",&p);
    printf("*p = %d\n",*p);
    

}