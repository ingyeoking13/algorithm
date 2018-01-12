#include <stdio.h>

int bsearch(int key, int l, int r, const int* arr){
	if (l<=r){
		int m = (l+r)/2;
		if (arr[m]==key) return m;
		else if ( arr[m]>key ) return bsearch(key, l, m-1, arr);
		else if ( arr[m]<key ) return bsearch(key, m+1, r, arr);
	}
	return -1;
}

int main(){
	int a[]= {1, 3, 5, 7, 9, 11, 13, 15};
	printf("%d\n", bsearch(11, 0, 7, a));
}



