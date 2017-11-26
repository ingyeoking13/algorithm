#include <stdio.h>
#include <stdlib.h>

int mycmp(const void* a, const void* b){ return *(int *)a - *(int *)b; }
int a[250001];
long long ans;
int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	int tmp;
	for (int i=0; i<n; i++) scanf("%d", ]);
	qsort (a, n, sizeof(int), mycmp);
	k=(k+1)/2; k--;
	for (int i=k; i<n-k; i++) ans+=a[i];
	printf("%lld\n", ans);
}
