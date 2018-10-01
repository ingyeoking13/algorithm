//faile
#include <stdio.h>
#include <string.h>
char arr[3073][6076];
int chk[3073]={1, 1, 1};

void dfs(int now){

	if (chk[now]) return;
	if (chk[now/2]) {
		
	};
	else dfs(now/2);
}

int main() {
	int n;
	scanf("%d",&n);

	for(int i=1; i<=n;i++)
		for(int j=0; j<=2*n;j++)
			arr[i][j] = ' ';

	arr[1][n-1] = '*'; arr[2][n-2] = '*'; arr[2][n] = '*';
	arr[3][n-3] = '*'; arr[3][n-2] = '*'; arr[3][n-1] = '*'; arr[3][n] = '*'; arr[3][n+1] = '*';

	dfs(n);

	for(int i=1; i<=n; i++) printf("%s\n", arr[i] );
}
