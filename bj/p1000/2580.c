#include <stdio.h>
int row[9][10], col[9][10], box[9][10], a[9][9];
int dfs(int now){
	if (now==81){
		for (int i=0; i<9; i++){
			for (int j=0; j<9; j++){
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		chk=1;
		return 1;
	}
	int x=now/9, y=now%9;
	if (a[x][y]==0){
		for (int i=1; i<10; i++){
			if ((!row[x][i]) && (!col[y][i]) && (!box[(x/3)*3+y/3][i])){
				row[x][i]=col[y][i]=box[(x/3)*3+y/3][i]=1;
				a[x][y]=i;
				if(dfs(now+1)) return 1;
				row[x][i]=col[y][i]=box[(x/3)*3+y/3][i]=0;
				a[x][y]=0;
			}
		}
	}
	else return dfs(now+1);
	return 0;
}
int main(){
	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++){
			scanf("%d", &a[i][j]);
			row[i][a[i][j]]=col[j][a[i][j]]=box[(i/3)*3+j/3][a[i][j]]=1;
		}
	}
	dfs(0);
}
