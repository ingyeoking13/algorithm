#include <stdio.h>

int main(){

	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		for (int j=3*n-i; j>0; j--) printf(" ");
		for (int j=0; j<2*i-1; j++) printf("*");
		printf("\n");
	}
	for (int i=1; i<=n; i++){
		for (int j=0; j<i-1; j++) printf(" ");
		for (int j=6*n-2*i; j>0; j--) printf("*");
		printf("\n");
	}
	for (int i=1; i<=n; i++){
		for (int j=0; j<n; j++) printf(" ");
		for (int j=0; j<2*n-2*i+1; j++) printf("*");
		for (int j=0; j<4*i-3; j++) printf(" ");
		for (int j=0; j<2*n-2*i+1; j++) printf("*");
		printf("\n");
	}


}
