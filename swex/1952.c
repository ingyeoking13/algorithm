#include <stdio.h>
int p[5], m[13], ans;
void dfs(int now, int pay){
	if (now>=13) {
		if (pay<ans) ans=pay;
		return ;
	}
	dfs(now+1, pay+m[now]*p[0]);
	dfs(now+1, pay+p[1]);
	dfs(now+3, pay+p[2]);
}
int main(){

	int T;
	scanf("%d", &T);

	for (int t=1; t<=T; t++){
		for (int i=0; i<4; i++) scanf("%d", &p[i]);
		for (int i=1; i<=12; i++) scanf("%d", &m[i]);
		ans=p[3];

		dfs(1, 0);
		printf("#%d %d\n", t, ans);
	}
}
