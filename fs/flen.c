/*
 * @Author       : fieldxy
 * @Date         : 2020-03-19 22:31:45
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-03-19 22:40:50
 * @Description  : In User Settings Edit
 * @FilePath     : \apue\fs\flen.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

static off_t flen(const char* fname)
{
	struct stat statres;

	if (stat(fname, &statres) < 0) {
		perror("stat()");
		exit(1);
	}

	return statres.st_size;
}

int main(int argc, char **argv)
{

	if (argc < 2) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	printf("%lld\n",(long long)flen(argv[1]));

	exit(0);
}