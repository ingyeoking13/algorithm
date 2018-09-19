#include <stdio.h>

int arr[1001][1001];

int v, e;
int dfs(int a, int b){
	arr[a][b]=arr[b][a]=0;

	for (int i=1; i<=v; i++){
		 if (arr[a][i]) dfs(a, i);
	}
	for (int i=1; i<=v; i++){
		 if (arr[b][i]) dfs(b, i);
	}
}
int main(){
	int a, b, ans=0;
	scanf("%d %d", &v, &e);

	for (int i=0; i<e; i++){
		scanf("%d %d", &a, &b);
		arr[a][b]=1;
		arr[b][a]=1;
	}

	for (int i=0; i<=v; i++) arr[i][i]=1;

	for (int i=1; i<=v; i++){
		for (int j=1; j<=i; j++){
			if (arr[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}

	printf("%d\n", ans);
}
