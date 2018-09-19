#include <stdio.h>
#include <string.h>

char input[50][17];
int ans=0, chk[26];
void dfs(int now){
	int len= strlen(input[now]);
	for (int i=0; i<len; i++) 




}
int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i=0; i<n;i++){
		char ch; int j=0, chk[26];
		memset(chk, 0, sizeof(chk));
		while(ch=getchar()){
			if (ch=='a' || ch=='n' || ch=='t' || ch=='i' || ch=='c') continue;
			if (ch=='\n'|| ch==EOF) break;
			if (!chk[ch-'a']) {input[i][j++]=ch; chk[ch-'a']=1;}
		}
	}
	k-=5;
	dfs(0);

}
