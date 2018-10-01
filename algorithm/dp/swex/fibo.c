#include <stdio.h>

long long dp[10001];
long long d(int n){
	if (n==1 || n==2) return dp[n]=1;
	if (dp[n]) return dp[n];
	return dp[n]=d(n-1)+d(n-2);
}
int main(){

	int n;
	scanf("%d", &n);
	d(n);
	printf("%lld\n", dp[n]);
}
