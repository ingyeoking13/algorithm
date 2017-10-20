#include <stdio.h>

int a[1001], d[1001], n;

int dp(int now){
	if (d[now]) return;
	d[now]=max(a[now]+dp(now-n), dp(now-1)+d[now-n]);
	return d[now];
}

int main(){

	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	printf("%d\n", dp(n));
}
