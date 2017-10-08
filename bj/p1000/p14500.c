#include <stdio.h>

int row, col, a[501][501], chk[501][501], ans=0;
int dx[4]={1, -1, 0, 0}, dy[4]= {0, 0, 1, -1};

void dfs(int x, int y, int depth, int point){

	if (depth==4){ 
		if (ans<point) ans=point;
		return ;
	}

	chk[x][y]=1;
	point+=a[x][y];

	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny= y+dy[i];
		if (nx >=0 && nx<row && ny>=0 && ny<col){
			if (chk[nx][ny]==0) {
				dfs(nx, ny, depth+1, point);
			}
		}
	}
	chk[x][y]=0;
}

void parkyu(int x, int y){
	int min=20000, sum=0, cnt=0;
	sum+=a[x][y];
	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny= y+dy[i];
		if (nx>=0 && nx<row && ny>=0 && ny<col){
			sum+=a[nx][ny]; cnt++;
			if (min > a[nx][ny]) min=a[nx][ny];
		}
	}
	if (cnt==4) { sum-=min; cnt--;}
	if (sum>ans && cnt==3) ans=sum;
}

int main(){

	scanf("%d %d", &row, &col);

	for (int i=0; i<row; i++){
		for(intj=0;j<col;j++){
			scanf("%d", &a[i][j]);
		}
	}

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			dfs(i,j, 0, 0);
			parkyu(i, j);
		}
	}

	printf("%d\n", ans);
}
