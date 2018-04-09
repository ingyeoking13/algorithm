#include <stdio.h>

void qsort(int* a, int l, int r){
	int i = l, j = r;
	int piv = arr[(l+r)/2];

	while(l<=r){
		while( arr[i] < piv) i++;
		while( arr[j] > piv) j--;

		if (i<=j ) {

		}

	}
};

int main(){
	int n =10;
	int a[10] ={9, 7, 5, 3, 2, 1, 8 ,6, 10, 4};

	qsort(a, 0, 9);
	for (int i=0; i<10; i++) printf("%d ", a[i]);
}
