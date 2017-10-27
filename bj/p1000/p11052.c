#include <stdio.h>

int a[1001], d[1001], n;

int max(int a, int b){ if (a<b) return b; return a;}
int dp(int n){
	if (n==1||n==0) return a[n];
	if (d[n]) return d[n];
	for (int i=1; i<=n; i++)
		d[n]=max(d[n], dp(n-i)+a[i]);
	return d[n];
}

int main(){

	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	printf("%d\n", dp(n));
}
