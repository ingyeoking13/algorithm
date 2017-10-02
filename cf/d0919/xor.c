#include <stdio.h>

int a[100001], d[100001];
int n, obj, ans=0;
int dfs(int now, int cnt, int i){
	if(i<10){
		if (now==0 && cnt==n) return 1;
		if (now==0) return 0;

		if (dfs(now^a[i+1], cnt+1, i+1)) printf("%d ", a[i+1]);
		dfs(now, cnt, i+1);
	}
	return 0;
}

int main(){
	scanf("%d %d", &n, &obj);
	for (int i=1; i<100001; i++) a[i]=i;

	dfs(obj, 0, 0);

}
