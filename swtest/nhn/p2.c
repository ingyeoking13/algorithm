#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[150], key[50], mes[50];
int main(){
	fgets(s, 150, stdin);

	int i=8, len=0;
	while('a'<=s[i] && s[i]<='z'){
		key[len++]=s[i++];
	}
	i++;
	int rot=atoi(s+i); 
	while(s[i++]!=' '); 
	len=0;
	while('a'<=s[i] && s[i]<='z'){
		mes[len++]=s[i++];
	}

	rot%=len;
	if (s[0]=='e'){
		for (int j=0; j<len; j++){
			int tmp=key[j]-'a';
			int now=mes[j]-'a';
			now+=tmp%26;
			mes[j]=now%26+'a';
		}
		for (int j=rot;j<rot+len;j++){
			printf("%c", mes[j%len]);
		}

		printf("\n");
	}
	else{
		char tmp[50]=""; int t=0;
		for (int j=len-rot;j<2*len-rot;j++){
			tmp[t++]=mes[j%len];
		}
		strcpy(mes, tmp);

		for (int j=0; j<len; j++){
			int tmp=key[j]-'a';
			int now=mes[j]-'a';
			now-=tmp;
			if (now <0) now+=26;
			mes[j]=now+'a';
		}
		printf("%s\n", mes);
	}
}
