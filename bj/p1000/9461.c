#include <stdio.h>

long long d[101]={0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

long long dfs(int n){
	if (d[n]) return d[n];
	return d[n]= dfs(n-1)+dfs(n-5);
}
int main(){

	dfs(100);
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
}
