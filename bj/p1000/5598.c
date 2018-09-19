#include <stdio.h>
#include <string.h>

char s[1001];
int main(){
	scanf("%s", s);
	int len=strlen(s);
	for (int i=0; i<len; i++){
		if ( s[i] -3 >='A') printf("%c", s[i]-3);
		else printf("%c", s[i]+26-3);
	}
	printf("\n");
}
