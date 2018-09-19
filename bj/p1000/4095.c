#include <stdio.h>

int a[1001][1001];
int min(int b, int c) { if (b<c) return b; return c;}
int main(){
	int row, col;
	scanf("%d %d", &row, &col);

	while(row && col){
		int max=0;
		for (int i=0; i<row; i++){
			for (int j=0; j<col; j++){
				scanf("%d", &a[i][j]);
			}
		}
		for (int i=0; i<row; i++){
			for (int j=0; j<col; j++){
				if ( i && j && a[i][j]){
					a[i][j]=min(min(a[i-1][j],a[i][j-1]),a[i-1][j-1])+1;
				}
				if (max<a[i][j]) max=a[i][j];
			}
		}
		printf("%d\n", max);
		scanf("%d %d", &row, &col);
	}
}
