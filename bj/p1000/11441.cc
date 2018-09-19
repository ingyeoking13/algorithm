#include <cstdio>

int a[100001], sum[100001];
int main(){
	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	for (int i=1; i<=n; i++) sum[i] = sum[i-1]+a[i];

	int m; scanf("%d", &m);
	while(m--){
		int from, to; scanf("%d %d", &from, &to);
		printf("%d\n", sum[to] - sum[from-1] );
	}
}
