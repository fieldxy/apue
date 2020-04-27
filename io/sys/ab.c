#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    putchar("a");
    write(1,"b",1);

    putchar("a");
    write(1,"b",1);

    putchar("a");
    write(1,"b",1);

    exit(0);
}