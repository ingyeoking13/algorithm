#include <stdio.h>

int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
void swap(int* a, int* b){ *a^=*b; *b^=*a; *a^=*b; }

int perm(){
	int i=8;
	while (i>0 && a[i-1] > a[i]) i--;
	if (i==0) { printf("End of permutation...\n"); return 0;}
	int j=8;
	while (a[i-1] >a[j]) j--;
	swap(&a[i-1], &a[j]);
	j=8;
	while(i<j){
		swap(&a[i], &a[j]);
		i++;
		j--;
	}
	return 1;
}
int main(){

	do{
		for (int i=0; i<9; i++) printf("%d ", a[i]);
		printf("\n");
	}while(perm());
}
