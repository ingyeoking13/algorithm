#include <stdio.h>

int arr[101][101], chk[101], ans=0;
void dfs(int a){
  chk[a]=1; ans++;
	for (int i=1; i<=100; i++){
		if (chk[i]==0 && arr[a][i]) 
			dfs(i);
	}
}


int main(){

	int v, e, a, b;
	scanf("%d %d", &v, &e);

	for (int i=0; i<e; i++){ 
		scanf("%d %d", &a, &b);
		arr[a][b]=1; arr[b][a]=1;
	}

	dfs(1);
	printf("%d\n", ans-1);
}
