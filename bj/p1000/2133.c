#include <stdio.h>

int d[31];

int dfs(int n){
	if (n%2==1) return 0;
	if (n<2) return 1;
	if (d[n]) return d[n];
	d[n]=3*dfs(n-2);
	for (int i=0; i<=n-4; i+=2){
		d[n]+=2*dfs(i);
	}
	return d[n];
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n",dfs(n));
}
