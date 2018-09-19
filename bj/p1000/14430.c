#include <stdio.h>

int a[300][300];
int max (int x, int y ) { return x<y?y:x;}
int main(){

	int row, col; scanf("%d %d", &row, &col);
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if (i==0 && j==0);
			else if ( i==0 ) a[i][j]+=a[i][j-1];
			else if ( j==0 ) a[i][j]+=a[i-1][j];
			else{
				a[i][j] = max(a[i-1][j], a[i][j-1]) +a[i][j];
			}
		}
	}
	printf("%d\n", a[row-1][col-1]);
}
