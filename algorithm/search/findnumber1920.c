#include <stdio.h>
#include <stdlib.h>

int binsearch(int* a, int val, int lo, int hi);
int mycmp(const void* a, const void* b){
return (*(int*)a - *(int*)b);
}

int main(){
int n, len, i, arr[100000]={0}, tmp;

scanf("%d", &len);
for (i=0; i<len; i++)
	scanf("%d", &arr[i]);

qsort(arr, len, sizeof(int), mycmp);

scanf("%d", &n);
for (i=0; i<n;i++){
	scanf("%d", &tmp);
	if(bsearch(&tmp, arr, len, sizeof (int), mycmp))
		printf("1\n");
	else printf("0\n");
}
return 0;
}
/*
int binsearch(int* a, int val, int lo, int hi){
	if (lo <= hi) {
		int mid= (lo+hi)/2;
		if (a[mid]==val) return 1;
		if (a[mid]<val) return binsearch(a, val, mid+1, hi);
		else if (a[mid]>val) return binsearch (a, val, lo, mid-1);
	}
	else return 0;
}
*/

