#include <stdio.h>

int a[20][20];
int main(){

	int n;
	scanf("%d", &n);

	//init
	for (int i=0; i<n; i++){
		for (int j=0; j<=i; j++){
			scanf("%d", &a[i][j]);
			a[j][i]=a[i][j];
		}
	}
	printf("\n");

	//printf
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
