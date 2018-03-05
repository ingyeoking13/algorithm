#include <stdio.h>

int a[64][64];
void quad(int x, int y, int n){

	int st= a[x][y], chk=0;
	for (int i=x; i<x+n; i++){
		for (int j=y; j<y+n; j++){
			if ( st!=a[i][j]) chk=1;
		}
	}

	if ( chk ){
		printf("(");
		quad(x, y, n/2); quad(x, y+n/2, n/2);
		quad(x+n/2, y, n/2); quad(x+n/2, y+n/2, n/2);
		printf(")");
	}
	else printf("%d",st);
	
}
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%1d", &a[i][j]);
		}
	}
	quad(0, 0, n);
	printf("\n");
}
