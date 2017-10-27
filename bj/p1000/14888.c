//samsung sw 2017
#include <stdio.h>

int a[11], b[4], n, max=-1<<30, min=1<<30;
void dfs(int i, int now, int b0, int b1, int b2, int b3){
	if (i>=n) {
		if (max<now) max=now;
		if (min>now) min=now;
		return ;
	}
	if (b0) dfs(i+1, now+a[i], b0-1, b1, b2, b3);
	if (b1) dfs(i+1, now-a[i], b0, b1-1, b2, b3);
	if (b2) dfs(i+1, now*a[i], b0, b1, b2-1, b3);
	if (b3) dfs(i+1, now/a[i], b0, b1, b2, b3-1);
}
int main(){
	scanf("%d", &n);

	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	scanf("%d %d %d %d", &b[0], &b[1], &b[2], &b[3]);
	dfs(1,a[0],b[0],b[1],b[2],b[3]);
	printf("%d\n%d\n", max, min);
}
