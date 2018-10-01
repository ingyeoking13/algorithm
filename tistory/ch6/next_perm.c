#include <stdio.h>

int a[7] = {7, 6, 3, 5, 4, 2, 1};
void swap(int* a, int* b){ *a^=*b; *b^=*a; *a^=*b; }

int main(){

	int i=6;
	while (i>0 && a[i-1] > a[i]) i--;
	if (i==0) { printf("Invalid\n"); return -1;}
	int j=6;
	while (a[i-1] >a[j]) j--;
	swap(&a[i-1], &a[j]);
	j=6;
	while(i<j){
		swap(&a[i], &a[j]);
		i++;
		j--;
	}

	for (int i=0; i<7; i++) printf("%d ", a[i]);
	printf("\n");
}
