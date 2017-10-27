#include <stdio.h>

int n, l, ans;
int a[101][101], b[101][101];
void dfs(int now, int cnt){
	if (now>n*n) return;

	if (cnt>=l){

		int tmp=0;
		for (int i=0; i<n; i++){
			int j=1, chk=1;
			while (j<n){
				if (a[i][j]!=a[i][j-1]) 
					if (a[i][j]!=a[i][j-1]+b[i][j]) chk=0;
				j++;
			}
			if (chk) tmp++;
		}

		for (int j=0; j<n; j++){
			int i=1, chk=1;
			while (i<n){
				if (a[i][j]!=a[i-1][j])
					if (a[i][j]!=a[i-1][j]+b[i][j]) chk=0;
				i++;
			};
			if (chk) tmp++;
		}

		if (ans<tmp) ans=tmp;
		return ;
	}

	b[now/n][now%n]=1;
	dfs(now+1, cnt+1);
	b[now/n][now%n]=0;
	dfs(now+1, cnt);
	
};
int main(){
	scanf("%d %d", &n, &l);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	dfs(0, 0);
	printf("%d\n", ans);
}
