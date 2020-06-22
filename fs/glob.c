/*
 * @Author       : fieldxy
 * @Date         : 2020-03-24 08:07:16
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-03-24 08:31:20
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\fs\glob.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
    
#define PAT  "/etc/a*.conf"

#if 0
int errfunc_(const char *errpath, int errno)
{
    puts(errpath);
    fprintf(stderr,"ERROR MSG:%s\n",streeror(errno));

    return 0;
}
#endif

int main()
{
    int i,err;

    glob_t globres;
    
    err = glob(PAT,0,NULL,&globres);
    if(err){
        printf("Error code = %d\n",err);
        exit(1);
    }

    for(i = 0; i < globres.gl_pathc; i++)
        puts(globres.gl_pathv[i]);

    globfree(&globres);
    exit(0);
}