#include <stdio.h>

int a[5]={5, 4, 2, 1, 3};
int main(){
	int n=5;
	printf("initial : ");
	for (int i=0; i<n; i++) printf("%d ", a[i]);
	printf("\n");

	for (int j=1; j<n; j++){
		int i=0;
		while (a[j]>a[i]) i++;
		int m=a[j];
		for (int k=0; k<j-i; k++) a[j-k] = a[j-k-1];
		a[i]=m;
		printf("j : %d  ...", j);
	for (int i=0; i<n; i++) printf("%d ", a[i]);
	printf("\n");
	}

}
