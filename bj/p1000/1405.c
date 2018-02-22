#include <stdio.h>

int prob[4], b[101][101];
int dx[4]={0, 0, 1, -1}, dy[4] ={1, -1, 0, 0};

double dfs(int x, int y, int now){

	if (b[x][y]) return 0;
	if (now==0) return 1;

	double ret=0;
	b[x][y]=1;

	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		ret+=dfs(nx, ny, now-1)*prob[i]/100;
	}

	b[x][y]=0;
	return ret;
}

int main(){
	int n; 
	scanf("%d %d %d %d %d", 
			&n, &prob[0], &prob[1], &prob[2], &prob[3]);

	printf("%lf\n", dfs(50, 50, n));
}
