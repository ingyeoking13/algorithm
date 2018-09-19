#include <stdio.h>

char s[32];
int main(){

	int T; scanf("%d", &T);
	getchar();
	while(T--){
		fgets(s, 32, stdin);
		if  ( 'a'<= s[0] && s[0] <='z' ) 
			s[0]=s[0]-'a'+'A';
		printf("%s", s);
	}
}
