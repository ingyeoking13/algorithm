#include <stdio.h>

char s[101];
int main(){
	fgets(s, 101,stdin);

	for (int i=0; s[i]; i++){
		if ('a' <=s[i] && s[i] <='z' ){
			printf("%c", (s[i]-'a'+13)%26+'a');
		}	
		else if ( 'A' <= s[i] && s[i] <= 'Z' ){
			printf("%c", (s[i]-'A'+13)%26+'A');
		}
		else printf("%c", s[i]);
	}
}
