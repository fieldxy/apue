#include <stdio.h>
#include <stdlib.h>

/*
    const int a;
    int const a;

    const int *p;
    int const *p;

    int ＊const p;

    const int * const * p;


*/
int main(void)
{
    int i = 1;
    int j = 100;
    const int * const p = &i;
    //F p = &j;
    //F *p = 100;
    printf("%d\n",*p);
#if 0
    int i = 1;
    int j = 10;
    int * const p = &i;

    //T *p = 10;
    //F p = &j;

    printf("%d\n",*p);
#endif
#if 0
    int i = 0;
    int j = 10;
    const int *p = &i;

    p = &j;
//T    i = 10;
//F    *p = 10;
    printf("%d\n",*p);
#endif
#if 0
    const float pi = 3.14;

    float *p = &pi;

    *p= 3.14159;

    printf("%f\n",*p);
#endif
    return 0;
}