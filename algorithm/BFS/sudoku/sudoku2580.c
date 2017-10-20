#include <stdio.h>

int sudoku[9][9];
int rowv[9][10];
int colv[9][10];
int boxv[9][10];

int bfs(int rc){
	int i, j;
	if (rc==81) {
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				printf("%d ", sudoku[i][j]);
			}
		printf("\n");
		}
	return 1;
	}
	int x = rc/9, y= rc%9;
	if(sudoku[x][y]) return bfs(rc+1);
	else {
		for (i=1; i<=9; i++){
			if(!rowv[x][i] && !colv[y][i] && !boxv[x/3*3+y/3][i]){
				sudoku[x][y]=i;  
				rowv[x][i]=1;colv[y][i]=1;boxv[x/3*3+y/3][i]=1;
				if (bfs(rc+1)) return 1;
				sudoku[x][y]=0;rowv[x][i]=0;colv[y][i]=0;
				boxv[x/3*3+y/3][i]=0;
			}
		}
	}
	return 0;
}

int main(){
	int i, j;
	for(i=0; i<9;i++){
		for(j=0; j<9; j++){
			scanf("%d", &sudoku[i][j]);
			if (sudoku[i][j]) {
					rowv[i][sudoku[i][j]]=1;
					colv[j][sudoku[i][j]]=1;
					boxv[i/3*3+j/3][sudoku[i][j]]=1;
			}
		}
	}
	bfs(0);
}

