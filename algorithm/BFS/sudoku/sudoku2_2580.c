#include <stdio.h>
int sudoku[9][9];
int cx[9][10], cy[9][10], cbox[9][10];
int dfs(int rc){
	if (rc==81) {
		for(int i=0; i<9;i++){
			for(int j=0; j<9;j++){
				printf("%d ",sudoku[i][j]);
			}
			printf("\n");
		} 
		return 1; 
	}

	int x= rc/9, y=rc%9;
	if (!sudoku[x][y]){
		for(int i=1; i<=9;i++){
			if(!cx[x][i] && !cy[y][i] && !cbox[x/3*3+y/3][i]){
				cx[x][i]=cy[y][i]=cbox[x/3*3+y/3][i]=1;
				sudoku[x][y]=i;
				if(dfs(rc+1)) return 1;
				sudoku[x][y]=0;
				cx[x][i]= cy[y][i]=cbox[x/3*3+y/3][i]=0;
			}
		}
	}
	else dfs(rc+1);
	return 0;
}

int main(){

	for(int i=0; i<9;i++){
		for(int j=0; j<9;j++){
			scanf("%d",&sudoku[i][j]);
			cx[i][sudoku[i][j]]=1;
			cy[j][sudoku[i][j]]=1;
			cbox[i/3*3+j/3][sudoku[i][j]]=1;
		}
	}
	dfs(0);
}
