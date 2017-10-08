#include <stdio.h>

int a[100001][4];
int main(){
	int row, col;
	scanf("%d %d", &row, &col);

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			scanf("%d",&a[i][j]); 
		}
	}

	for (int i=1; i<row; i++){
		for (int j=0; j<col; j++){
			a[i][j]+=a[i-1][j];
		}
	}

	int chk=0;
	int max=(row%2)?row/2+1:row/2;
	if (row==1) max=0;

	for (int j=0; j<col; j++){
		if ( a[row-1][j] > max) 
			chk=1;	
	}

	if (chk) printf("NO\n");
	else printf("YES\n");

}
