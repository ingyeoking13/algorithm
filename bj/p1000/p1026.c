#include <stdio.h>
#include <stdlib.h>

int mycmp(const void* a, const void* b){ return *(int *) a - *(int *) b; }
int mycmp2(const void* a, const void* b){ return *(int *) b - *(int *) a; }

int a[51], b[51];
int main(){

	int n;
	scanf("%d", &n);

	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<n; i++) scanf("%d", &b[i]);

	qsort(a, n, sizeof(int), mycmp);
	qsort(b, n, sizeof(int), mycmp2);

	int ans=0;
	for (int i=0; i<n; i++) ans+=a[i]*b[i];

	printf("%d\n", ans);
}
