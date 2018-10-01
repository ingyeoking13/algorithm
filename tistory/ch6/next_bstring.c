#include <stdio.h>

int a[10]={1, 0, 0, 0, 1, 0, 0, 1, 1, 1};
int main(){

	int i=9;
	while (i>=0 &&a[i]==1) a[i--]=0;
	a[i]=1;

	for (int j=0; j<10; j++) printf("%d ", a[j]);
	printf("\n");
}
