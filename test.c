#include <stdio.h>
#include <string.h>

int main(){
	char a[][30] = {"abc", "def"};
	char b[][30] = {"myappend", "myappend2~"};
	char s[4][30];

	int cnt=0;
	for (int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			strcpy(s[cnt], a[i]);
			strcpy(s[cnt]+strlen(s[cnt]), b[j]);
			cnt++;
		}
	}
	for (int i=0; i<4; i++) printf("%s\n", s[i]);
}
