#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	DIR *dp;
	struct dirent *dir;

	if ((dp = opendir(".")) == 0){
		fprintf(stderr, "director open error\n");
		exit(-1);
	}

	while((dir = readdir(dp)) != 0){
		if (dir->d_ino == 0 ) continue;
		printf("%s\n", dir->d_name);
	}
	closedir(dp);
}
