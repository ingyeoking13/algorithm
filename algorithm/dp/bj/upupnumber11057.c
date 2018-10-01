#include <stdio.h>
#define mod 10007

long long d[1001][10];
int main(){

	int n;
	scanf("%d", &n);
	for (int i=0; i<=9; i++) d[1][i]=1;
	for (int i=2; i<=n; i++){
		for (int j=0; j<=9; j++){
			for(int k=j;k<=9;k++) d[i][j]+=d[i-1][k]%mod;
		}
	};
	long long ans=0;
	for (int i=0; i<=9;i++)  ans+=d[n][i];
	printf("%lld\n", ans%mod);

}
