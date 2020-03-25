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
	strrchr()
}
static int64_t mydu(const char* path)
{
	struct stat statres;
	char nextpath[PATHSIZE];
	int i, sum;
	glob_t globres;

	if (lstat(path, &statres) < 0) {
		perror("lstat()");
		exit(1);
	}

	if (!S_ISDIR(statres.st_mode))
		return statres.st_blocks/2;

	// /a/b/c/d/e/f
	strncpy(nextpath, path, PATHSIZE);
	strncat(nextpath, "/*", PATHSIZE);
	glob(nextpath, 0, NULL, &globres);

	strncpy(nextpath, path, PATHSIZE);
	strncat(nextpath, "/.*", PATHSIZE);
	glob(nextpath, GLOB_APPEND, NULL, &globres);

	for (i = 0; i <globres.gl_pathc; i++)
	{
		if(path_noloop(globres.gl_pathv[i]))
		sum+= mydu(globres.gl_pathv[i]);
	}

	sum += statres.st_blocks;

	return sum / 2;
}

int main(int argc, char** argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage.....");
		exit(1);
	}

	printf("%ld\n",mydu(argv[1]));


	exit(0);
}