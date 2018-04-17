#include <stdio.h>

int d[51][51][51];
int dfs(int a, int b, int c){
	if ( a<=0 || b<=0 || c<=0 ) return 1;
	if (d[a][b][c] ) return d[a][b][c];
	if ( a>20 || b>20 || c>20 ) return d[a][b][c] =dfs(20, 20, 20);
	if ( a<b && b<c )  return d[a][b][c]= dfs(a, b, c-1) + dfs(a, b-1, c-1) - dfs(a, b-1, c);
	return d[a][b][c] = dfs(a-1, b, c) + dfs(a-1, b-1, c) + dfs(a-1, b, c-1) - dfs(a-1, b-1, c-1);

}
int main(){
	while(1){
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		if ( a==-1 && b==-1 && c==-1) break;

		printf("w(%d, %d, %d) = ", a, b, c);
		printf("%d\n", dfs(a, b, c));
	}
}
