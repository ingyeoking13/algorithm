#include <stdio.h>

int a[1000][1000]; 
int dp[1000][1000][2], r, c, hp=5;
int v[1000][1000][2];
int dx[2] ={1, 0}, dy[2]={0, 1};
int min (int x, int y){ 
	if ( x<=0 && y<=0) return -1;
	if ( x<=0) return y; if ( y<=0) return x;
	return x<y?x:y; 
};

int dfs(int row, int col, int d){
    if ( row==0 && col ==0) return dp[row][col][d]=hp;
    if ( v[row][col][d] ) return dp[row][col][d];
    v[row][col][d]=1;
    dp[row][col][d]=-1;

		int nx = row-dx[d],ny= col-dy[d];
		if ( 0<=nx && nx<r && 0 <=ny && ny<c){
			for (int i=0; i<2; i++){
				if ( dfs(nx, ny, i) >0 ){
					dp[row][col][d] = min (dfs(nx,ny,i), dp[row][col][d]);
				}
			}
		}

		if ( dp[row][col][d] <= 0 ) return dp[row][col][d];

		dp[row][col][d]+=a[row][col];
		if ( dp[row][col][d] <= 0 ) return dp[row][col][d]=-1;
		else return dp[row][col][d];
}

int main(){

	printf("input digit r c hp, and then a[i][j]\n");
	scanf("%d %d %d", &r, &c, &hp);
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	int ans = min(dfs(r-1, c-1, 0), dfs(r-1, c-1, 1));

	printf("%d\n\n", ans);

	/*
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			printf("%d ", dp[i][j][0]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			printf("%d ", dp[i][j][1]);
		}
		printf("\n");
	}
	*/
}
