#include <stdio.h>

char a[6560][6560];
int n;
void rec(int x, int y, int size){
}

int main(){
	scanf("%d", &n);

	rec(0, 0, n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}
