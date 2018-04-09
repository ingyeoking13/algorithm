#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define PORT 9000

char buffer[BUFSIZ] = "hello,world.suck\n";
int main(){
	int c_sock, s_sock;
	struct sockaddr_in s_addr, c_addr;

	s_sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(PORT);

	if ( bind(s_sock, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1){
		printf("Can not Bind\n");
		return -1;
	}

	if ( listen(s_sock, 5) == -1){
		printf("listen Fail\n");
		return -1;
	}

	while(1){
		int len = sizeof(c_addr);
		c_sock = accept(s_sock, (struct sockaddr *) &c_addr , &len);

		// 여기서부터기능 코딩
		char rbuf[BUFSIZ];
		char *tmp = rbuf;
		int l=0;
		DIR* dp;
		struct dirent *dir;

		while(read(c_sock, tmp, 1) >0 ){
			if (l == BUFSIZ) break;
			if (*tmp == '\r') continue;
			if (*tmp == '\n' ) break;
			if (*tmp == 0) break;

			l++;tmp++;
		}
		rbuf[l] = 0;

		if (!strcmp(rbuf, "ls")) {

			if (( dp = opendir(".")) == 0){
				write(c_sock, "directory open error", 30);
			}
			else{
				while((dir = readdir(dp)) != 0){
					if ( dir->d_ino == 0 ) continue;
					write(c_sock, dir->d_name, strlen(dir->d_name));
				}
				closedir(dp);
			}
		}
		close(c_sock);
	}
	close(s_sock);

}
