#include <stdio.h>
int a[301][301], d[301][301];
int main(){
	int row, col;
	scanf("%d %d", &row, &col);
	for (int i=1; i<=row; i++)
		for (int j=1; j<=col; j++)
			scanf("%d", &a[i][j]);

	for (int i=1; i<=row; i++){
		for (int j=1; j<=col; j++){
			if (i==1 & j==1) d[i][j]=a[i][j];
			else if(i==1) d[i][j]+=d[i][j-1]+a[i][j];
			else if(j==1) d[i][j]+=d[i-1][j]+a[i][j];
			else d[i][j]+=d[i][j-1]+d[i-1][j]-d[i-1][j-1]+a[i][j];
		}
	}
	
	int n; scanf("%d", &n);
	int lx, ly, rx, ry;
	while(n--){
		scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
		int ans= d[rx][ry]-d[rx][ly-1]-d[lx-1][ry]+d[lx-1][ly-1];
		printf("%d\n", ans);
	}
}
