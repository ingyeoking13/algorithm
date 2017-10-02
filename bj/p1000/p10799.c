#include <stdio.h>

char in[100001];
int main(){

	int len=0, ans=0;
	scanf("%s", in);
	for (int i=0; in[i]; i++){
		if (in[i] == '(' && in[i+1] == ')'){ans+=len; i++;}
		else if (in[i]=='(') len++;
		else if (in[i]==')') { len--; ans++; }
	}
	printf("%d\n", ans);
}
