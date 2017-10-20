#include <stdio.h>

int n, ans;
int chk_col[15];
int chk_dig[30];
int chk_dig2[30];

int chk(int row, int col){
	if (!chk_col[col] && !chk_dig[row+col] && !chk_dig2[n-1-col+row])
		return 1;
	return 0;
}

void bfs(int row){
	if(row==n){ ans++; return;} 
	int col;
	for(col=0;col<n;col++){
		if(chk(row, col)){
			chk_col[col]=1;
			chk_dig[row+col]=1;
			chk_dig2[n-1-col+row]=1;
			bfs(row+1);
			chk_col[col]=0;
			chk_dig[row+col]=0;
			chk_dig2[n-1-col+row]=0;
		}
	}
}

int main(){

	scanf("%d", &n);
	bfs(0);
	printf("%d\n", ans);
}
