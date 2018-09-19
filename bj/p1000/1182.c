#include <stdio.h>

int a[21], n, obj, ans;

void dfs(int i, int now){
	if (i==n) {
		if  (now==obj) ans++;
		return ;
	}

	dfs(i+1, now+a[i]);
	dfs(i+1, now);
}

int main(){
	scanf("%d %d", &n, &obj);
	for (int i=0; i<n; i++) scanf("%d", &a[i]); 

	dfs(0, 0);
	printf("%d\n", obj?ans:ans-1);
}
