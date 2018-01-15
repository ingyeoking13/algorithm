#include <stdio.h>
#include <stdlib.h>

int a[200000], b[200000], st[200000];
int mycmp(const void* a, const void* b){
	return *(int *)a - *(int *)b;
}
int main(){
	int n, t; scanf("%d %d", &n, &t);
	for (int i=0; i<n; i++){
		scanf("%d %d", &a[i], &b[i]);
	}

	int l=0, r=n-1;
	while(l < r){
		int m=(l+r)/2;
		int top=0; 
		for (int i=0; i<n; i++){
			if (a[i]>=m) st[top++] = b[i];
		}
		qsort(st, st+top);
		int ans=0, rem=t;
		for (int i=0; i<top; i++){
			if (rem >= st[i]) rem -= st[i], ans++;
			else break;
		}
		if (ans >= m) l=m+1;
		else r=m-1;
	}
	printf("%d\n%d\n", );
}
