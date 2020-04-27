#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char *name[5] = {"FO","BA","GR","FOR","COM"};

    for(i = 0; i < 5; i++){
        puts(name[i]);
    }
}