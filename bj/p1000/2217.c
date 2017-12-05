#include <stdio.h>
#include <stdlib.h>

int a[100000];
int mycmp(const void *x, const void *y) {
 	return *(int *)y- *(int *)x;
}
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), mycmp);
	int max=a[0];
	for (int i=1; i<n; i++){
		if ( max<=a[i]*(i+1)) max=a[i]*(i+1);
	}
	printf("%d\n", max);
}
