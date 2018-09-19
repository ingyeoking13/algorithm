#include <stdio.h>
#include <string.h>
char s[5002];int d[5002];
int dfs(int n){
	if (n<0) return 1;
	if (d[n]) return d[n];

	int now = s[n]-'0', prev=s[n-1]-'0';
	if (now!=0) d[n]=dfs(n-1);

	int dig =prev*10+now;
	if (10<=dig && dig<=26) d[n]+=dfs(n-2);
		
	d[n]%=1000000;
	return d[n];
}
int main(){
	for (int i=0; i<92; i++){
		for (int j=0; j<5002;j++) d[j]=0;
		scanf("%s", s);
		int n=strlen(s);
		printf("%d\n", dfs(n-1));
	}
}
