#include <stdio.h>

void swap(int* a, int* b);

int next_permutation(int *a, int n){
	int i=n-1;
	while (i>0 && a[i-1]>= a[i]) i--;
	if (i<=0) return 0;
	int j=n-1;
	while (a[j]<a[i-1]) j--;
	swap(&a[i-1],&a[j]);
	j=n-1;
	while(i<j){
		swap(&a[j],&a[i]);
		i++;
		j--;
	}
	return 1;
}

int main(){

	int i, scale;
	int arr[10000];

	scanf("%d", &scale);
	for (i=0;i<10000;i++) arr[i]=0;
	for (i=0;i<scale;i++) scanf("%d", &arr[i]);

	if(next_permutation(arr, scale))
		for (i=0; i<scale;i++)
			printf("%d ", arr[i]);

	else printf("-1");
	printf("\n");

	return 0;
}

void swap(int* a, int* b){
	int tmp=*b;
	*b=*a;
	*a=tmp;
}
