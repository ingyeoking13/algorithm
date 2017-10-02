#include <stdio.h>

int main(){

	int i, j, n;
	scanf("%d", &n);

	for(i=0; i<2*n-1; i++){
		if (i<n){
			for(j=0;j<i+1;j++) printf("*");
			for(j=0;j<2*(n-i-1);j++) printf(" ");
			for(j=0;j<i+1;j++) printf("*");
			printf("\n");
		}
		else {
			for(j=2*n-1;j>i;j--) printf("*");
			for(j=2*i;j>2*(n-1);j--) printf(" ");
			for(j=2*n-1;j>i;j--) printf("*");
			printf("\n");
		}
	}
	return 0;
}

