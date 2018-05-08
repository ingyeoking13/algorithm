#include <stdio.h>
#define SZ 10

int part(int* arr, int lo, int hi){
	int now = arr[lo];

	for (int j= hi-1; j > lo; j--){
		if ( arr[j] <= now) 

	}

}

void qsort(int* arr, int lo, int hi){
	if ( lo < hi ){
		int pos = part(arr, lo, hi);
		qsort(lo, pos-1);
		qsort(pos+1, hi);
		printf("[ ");
		for (int i=0; i<SZ; i++) printf("%d ", arr[i]);
		printf("]\n");
	}
}

int main(){
	int arr[] = {5, 8, 3, 4, 2, 9, 10, 6, 7, 1};
	int n = 10;

	qsort(arr, 0, n-1);

}
