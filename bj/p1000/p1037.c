#include <stdio.h>
#include <stdlib.h>

int mycmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){

	int n, a[50];
	scanf("%d", &n);
	for (int i=0; i<n;i++) scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), mycmp);
	printf("%d\n", a[0]*a[n-1]);
}
