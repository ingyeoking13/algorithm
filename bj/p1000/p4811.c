//fail
#include <stdio.h>
#include <string.h>

int n, ans;
void dfs(int now, int h, int w){
	if (now==2*n && w==0) {ans++; return;}
  else if (now==2*n) return;
	if (h>0) dfs(now+1, h-1, w+1); 
	if (w>0) dfs(now+1, h, w-1);
}

int main(){
	scanf("%d", &n);
	while (n){
		ans=0;
		dfs(0, n, 0);
		printf("%d\n", ans);
		scanf("%d", &n);
	}
}
