#include <stdio.h>

char str[5000];
int first=1;
int main(){

	fgets(str, 5000, stdin);
	int i;
	char ch;
	while(ch=str[i++]){
		if(('A'<=ch && ch<='Z') ||('a'<=ch && ch<='z')) {
			if('a'<=ch && first){
				str[i-1] = ch-'a'+'A';
				first=0;
			}
			else if (ch<='Z' && !first){
				str[i-1] = ch-'A'+'a';
			}
			else if (first) first=0;
		}
		else if(ch==' ') first=1;
		else if(first && ch!=' ') first=0;
		else if(ch=='\n') break;
	}

	printf("%s", str);
}
