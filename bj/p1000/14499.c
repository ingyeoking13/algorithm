#include <stdio.h>
int dice[6], a[20][20];
int dx[4]={0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int main(){
	int row, col, x, y, m; 
	scanf("%d %d %d %d %d", &row, &col, &x, &y, &m);
	for (int i=0; i<row; i++)
		for (int j=0; j<col; j++)
			scanf("%d", &a[i][j]);

	while(m--){
		int tmp; scanf("%d", &tmp); tmp--;
		int nx = x+dx[tmp], ny = y+dy[tmp];
		if (nx>=0 && ny>=0 && nx<row && ny<col){
			int ndice[6];
			if (tmp==0){
				ndice[0]=dice[0]; ndice[2]=dice[2];
				ndice[4]=dice[1]; ndice[3]=dice[4]; 
				ndice[1]=dice[5]; ndice[5]=dice[3]; 
			}
			else if (tmp==1){
				ndice[0]=dice[0]; ndice[2]=dice[2];
				ndice[1]=dice[4]; ndice[4]=dice[3]; 
				ndice[5]=dice[1]; ndice[3]=dice[5]; 
			}
			else if (tmp==2){
				ndice[4]=dice[4]; ndice[5]=dice[5];
				ndice[1]=dice[0]; ndice[2]=dice[1];
				ndice[3]=dice[2]; ndice[0]=dice[3];
			}
			else if (tmp==3){
				ndice[4]=dice[4]; ndice[5]=dice[5];
				ndice[0]=dice[1]; ndice[1]=dice[2];
				ndice[2]=dice[3]; ndice[3]=dice[0];
			}
			if (a[nx][ny]) ndice[1]=a[nx][ny], a[nx][ny]=0; 
			else a[nx][ny]=ndice[1];
			printf("%d\n", ndice[3]);
			for (int i=0; i<6; i++) dice[i]=ndice[i];
			x=nx, y=ny;
		}
	}
}
