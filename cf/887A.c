#include <stdio.h>
#include <string.h>

char s[105];
int main(){
	scanf("%s", s);
	int len=strlen(s);
	int i=0, cnt=0;
	while (s[i]=='0') i++;
	for (;i<len; i++) if (s[i]=='0') cnt++; 
	if (cnt>=6 ) printf("yes\n");
	else printf("no\n");
}
