#include <stdio.h>
#include <stdlib.h>
int a[35], n, m, arr1[1<<20], arr2[1<<20];
int idx1, idx2;
int mycmp(const void* a, const void* b) { return *(int *)a - *(int *)b;}
void dfs(int i, int sum, int type){
	if (type && i==n) {arr2[idx2++] = sum; return;}
	else if (!type && i==n/2) {arr1[idx1++]= sum; return ; }
	dfs(i+1, (sum+a[i])%m , type);
	dfs(i+1, sum, type);
}
int lbound(int v){
	int s=0, e=idx2;
	while (e>s){
		int mid=(s+e)/2;
		if (arr2[mid] >= v) e=mid;
		else s=mid+1;
	}
	return e;
}
int main(){
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
		a[i]%=m;
	}
	qsort (a, n, sizeof(int), mycmp);

	dfs(0, 0, 0);
	dfs(n/2, 0, 1);
	arr1[idx1++]=0;
	arr2[idx2++]=0;

	for (int i=0; i<idx1; i++) arr1[i]%=m;
	for (int i=0; i<idx2; i++) arr2[i]%=m;

	qsort(arr1, idx1, sizeof(int), mycmp);
	qsort(arr2, idx2, sizeof(int), mycmp);

	int ans=0;
	for (int i=0; i<idx1; i++){
		int j=lbound(m-arr1[i]);
		j--;
		int tmp=(arr1[i]+arr2[j])%m;
		if ( j>=0) ans=tmp>ans?tmp:ans;
	}
	printf("%d\n", ans);
}
