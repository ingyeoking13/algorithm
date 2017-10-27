#include <stdio.h>

int d[201][201];
int dfs(int n, int k){
	if (k==1) return 1;
	if (d[n][k]) return d[n][k];
	for (int i=0; i<=n; i++){
		d[n][k]+=dfs(n-i,k-1);
		d[n][k]%=1000000000;
	}
	return d[n][k];
};

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", dfs(n, k));
}
