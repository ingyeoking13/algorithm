#include <stdio.h>

int main(){

	for (int i=0; i<81; i++){
		printf("%d ", i/27*3+i%9/3);
		if (i%9==8) printf("\n");
	}
	printf("\n");
	for (int i=0; i<81; i++){
		printf("%d ", i/9);
		if (i%9==8) printf("\n");
	}

	printf("\n");
	for (int i=0; i<81; i++){
		printf("%d ", i%9);
		if (i%9==8) printf("\n");
	}
}
