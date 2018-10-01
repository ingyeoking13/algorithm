#include <stdio.h>
#include <string.h>

int d[500][500][500];
char s[500][501];
int dx[]={-1, 1, 0, 0}, dy[] ={0, 0, -1, 1};

int dfs(int sx, int sy, int ex, int ey){
	return 1;

}

int main(){

	int T; scanf("%d", &T);

	for (int t=1; t<=T; t++){
		memset(d, -1,sizeof(d));
		int n; scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%s", s[i]);
		for (int i=0; i<n; i++) d[i][i][i][i]=1;

		int ans=0;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				ans+=dfs(0, 0, i,j);
			}
		}
		printf("%d\n", ans);
	}

}
