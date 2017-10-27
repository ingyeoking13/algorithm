#include <stdio.h>
#include <math.h>

int d[100001];
int min(int a, int b) { if (a<b) return a; return b; }
int dfs(int n){
	if (n<1) return 0;
	if (d[n]) return d[n];
	d[n]=n;
	for (int i=1; i*i<=n; i++){
		if(n>=i*i) d[n]=min(dfs(n-i*i)+1, d[n]);
	}
	return d[n];
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", dfs(n));
}
