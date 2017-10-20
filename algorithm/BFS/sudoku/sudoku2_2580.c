#include <stdio.h>
int sudoku[9][9];
int cx[9][10], cy[9][10], cbox[9][10];

void bfs(int rc){
	if (rc==81) {
		for(int i=0; i<9;i++){
			for(int j=0; j<9;j++){
				printf("%d ",sudoku[i][j]);
			}
			printf("\n");
		} return; }

	if (!sudoku[rc/9][rc%9]){
		for(int i=1; i<=9;i++){
			if(!cx[rc/9][i] && !cy[rc%9][i] && !cbox[rc/9/3*3+rc%9/3][i]){
				cx[rc/9][i]=1;  cy[rc%9][i]=1; cbox[rc/9/3*3+rc%9/3][i]=1;
				sudoku[rc/9][rc%9]=i;
				bfs(rc+1);
				sudoku[rc/9][rc%9]=i;
				cx[rc/9][i]=0;  cy[rc%9][i]=0; cbox[rc/9/3*3+rc%9/3][i]=0;
			}
		}
	}
	else{
		bfs(rc+1);
	}
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

	bfs(0);

}
