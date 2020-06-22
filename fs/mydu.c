/*
 * @Author       : fieldxy
 * @Date         : 2020-03-25 23:15:44
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-03-25 23:45:48
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\fs\mydu.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <glob.h>
#include <unistd.h>

#define PATHSIZE	1024

static path_noloop(const char *path)
{
	char* pos;
	pos = strrchr(path, '/');
	if (pos = NULL) {
		exit(1);
	}
	if ((strcmp(pos + 1, ".") == 0) || (strcmp(pos + 1, "..") == 0))
		return 0;
	return 1;
}

static int64_t mydu(const char* path)
{
	struct stat statres;
	char nextpath[PATHSIZE];
	int i;
    int64_t sum;
	glob_t globres;

	if (lstat(path, &statres) < 0) {
		perror("lstat()");
		exit(1);
	}

	if (!S_ISDIR(statres.st_mode))
		return statres.st_blocks;

	// /a/b/c/d/e/f
	strncpy(nextpath, path, PATHSIZE);
	strncat(nextpath, "/*", PATHSIZE);
	glob(nextpath, 0, NULL, &globres);

	strncpy(nextpath, path, PATHSIZE);
	strncat(nextpath, "/.*", PATHSIZE);
	glob(nextpath, GLOB_APPEND, NULL, &globres);

    sum = 0;

	for (i = 0; i <globres.gl_pathc; i++)
	{
		if(path_noloop(globres.gl_pathv[i]))
		    sum += mydu(globres.gl_pathv[i]);
	}

	sum += statres.st_blocks;

	return sum;
}

int main(int argc, char** argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage.....");
		exit(1);
	}

	printf("%lld\n",mydu(argv[1])/2);


	exit(0);
}