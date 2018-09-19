#include <stdio.h>

char s[11][3];
int a[10], chk[10];
long long mn=1<<30, mx=0;
char mnans[11], mxans[11];

void dfs(int now, int len){

	if ( now == len+1){

		long long tmp = 0;
		for (int i=0; i<now; i++){
			tmp*=10;
			tmp= tmp +a[i];
		}
		if (tmp > mx) {
			mx=tmp;
			for (int i=now-1; i>=0; i--) {
				mxans[i] = (mx%10)+'0';
				mx/=10;
			}
		}
		if (tmp < mn ){
		 	mn =tmp;
			for (int i=now-1; i>=0; i--) {
				mnans[i] = (mn%10)+'0';
				mn/=10;
			}
		}
		return ;
	}

	for (int i=0; i<=9; i++){
		if (chk[i]) continue;
		if ( now ==0 || (a[now-1]>i && s[now-1][0] =='>') || (a[now-1]<i && s[now-1][0]=='<')) {
			a[now]=i; 
			chk[i]=1;
			dfs(now+1, len);
			chk[i]=0;
		}
	}
	return;
}

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%s",s[i]);
	dfs(0, n);
	
	printf("%s\n",mxans);
	printf("%s\n",mnans);
	/*
	for (int i=n; i>=0; i--) printf("%d",mxans[i]);
	printf("\n");
	for (int i=n; i>=0; i--) printf("%d",mnans[i]);
	printf("\n");
	*/
}
