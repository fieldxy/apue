#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define  PAT	"/etc"

int	main()
{
	DIR *dp=NULL;
	struct dirent * cur;
	dp = opendir(PAT);
	if (dp == NULL) {
		perror("opendir()");
		exit(1);
	}

	while ((cur = readdir(dp)) != NULL)
	{
		puts(cur -> d_name);
	}

	closedir(dp);



	exit(0);
}