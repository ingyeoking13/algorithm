#include <stdio.h>
#include <stdlib.h>

int parent[100001], size[1000001];
int ufind(int n){
	if (n==parent[n]) return n;
	else return parent[n]=ufind(parent[n]);
}
int mycmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int main(){
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) parent[i]=i;
	for (int i=1; i<=n; i++) {
		int tmp;
		scanf("%d", &tmp);
		parent[i]=ufind(tmp);
	}
	for (int i=1; i<=n; i++) size[ufind(i)]++;

	qsort(size, n+1, sizeof(int), mycmp);
	long long ans=0;
	for (int i=0; i<n; i++) ans+=(long long)size[i]*size[i];
	ans+=(long long)size[0]*size[1]*2;
	printf("%lld\n",  ans);
}
