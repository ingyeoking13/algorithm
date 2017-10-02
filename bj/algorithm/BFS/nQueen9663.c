#include <stdio.h>

int chess[15][15];
int n;
int ans;

int chk(int row, int col){
	int x, y, i; 
//	for(i=col-1;i>=0;i--){
//		if(chess[row][i]) return 0;
//	}
	for(i=row-1;i>=0;i--){
		if(chess[i][col]) return 0;
	}
	x=row-1; y=col-1;
	while(x>=0 && y>=0){
		if(chess[x][y]) return 0;
		x--; y--;
	}

	x=row-1; y=col+1;
	while(x>=0 && y<n){
		if(chess[x][y]) return 0;
		x--; y++;
	}

	return 1;
}
void calc(int row){
  int col;
	if(row==n){
		ans+=1;
	}
	for(col=0;col<n;col++){
		chess[row][col]=1;
		if(chk(row, col)){
			calc(row+1);
		}
		chess[row][col]=0;
	}
}
int main(){

	scanf("%d", &n);
	calc(0);
	printf("%d\n", ans);
	return 0;
}
