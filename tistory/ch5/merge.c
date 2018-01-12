#include <stdio.h>

void merge(int* arr, int l, int m, int r){

	int len1 = m-l+1, len2 = r-m;
	int tmpa[len1], tmpb[len2];
	for (int i=0; i<len1; i++) tmpa[i] = arr[l+i];
	for (int i=0; i<len2; i++) tmpb[i] = arr[m+1+i];

	int i=0, j=0, k=l;

	while ( i<len1 && j<len2 ){
		if ( tmpa[i] > tmpb[j] ) arr[k++] = tmpb[j++];
		else 										 arr[k++] = tmpa[i++];
	}

	while ( i<len1 ) arr[k++] = tmpa[i++];
	while ( j<len2 ) arr[k++] = tmpb[j++];

	printf("l, r : %d %d merged...\t", l, r);
	for (int i=l; i<=r; i++) printf("%d ", arr[i]);
	printf("\n");
}

void divide(int *arr, int l, int r){
	printf("l, r : %d %d divided...\n", l, r);
	if (l<r){
		int m = (l+r)/2;
		divide(arr, l, m);
		divide(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

int main(){
  int a[] = {9, 7, 5, 4, 3, 2, 1, 0, 13, 25, -13, -44, -10}; //13

	printf("origin array\n");
	for (int i=0; i<13; i++) printf("%d ", a[i]);
	printf("\n");
	for (int i=0; i<13; i++) printf(a[i]/10?"%d  ":"%d ", i);
	printf("\n===========\n\n");

	divide(a, 0, 12);

	printf("\n===========\n");
	for (int i=0; i<13; i++) printf("%d ", a[i]);
	printf("\n");
}
