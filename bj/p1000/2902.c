#include <stdio.h>

char s[101];
int main(){
	scanf("%s", s);
	int i=0;
	while (s[i]){
		if (0<=s[i]-'A' && s[i]-'A'<=25) printf("%c",s[i]);
		i++;
	}
	printf("\n");
}
