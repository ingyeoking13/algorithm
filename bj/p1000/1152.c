//fail
#include <stdio.h>
#include <string.h>

char s[1000001];
int main(){
	fgets(s, 1000001,stdin);
	int len=strlen(s), ans=0, chk=1;
	for (int i=0; i<len; i++) {
		if (s[i]==' ') { if(chk) ans++; chk^=1;}
		else chk=1;
	}
	if (s[len-1]==' ') ans--;
	if (s[0]==' ') ans--;
	if (len==1 && s[0]==' ')  printf("0\n");
	else 	printf("%d\n", ans+1);
}
