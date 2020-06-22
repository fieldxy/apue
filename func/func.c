#include <stdio.h>
#include <stdlib.h>

void a(void);
void b(void);
void c(void);

int main(void)
{

    printf("[%s]begin!\n",__FUNCTION__);
    printf("[%s]cell a()!\n",__FUNCTION__);
    a();
    printf("[%s]a() returned!\n",__FUNCTION__);
    printf("[%s]end!\n",__FUNCTION__);
}

void a(void)
{

    printf("[%s]begin!\n",__FUNCTION__);
    printf("[%s]cell b()!\n",__FUNCTION__);
    b();
    printf("[%s]b() returned!\n",__FUNCTION__);
    printf("[%s]end!\n",__FUNCTION__);
}

void b(void)
{

    printf("[%s]begin!\n",__FUNCTION__);
    printf("[%s]cell c()!\n",__FUNCTION__);
    c();
    printf("[%s]c() returned!\n",__FUNCTION__);
    printf("[%s]end!\n",__FUNCTION__);
}

void c(void)
{

    printf("[%s]begin!\n",__FUNCTION__);
    printf("[%s]end!\n",__FUNCTION__);
}