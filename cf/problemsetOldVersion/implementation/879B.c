#include <stdio.h>

int a[501];
int main(){
	int n;long long k;
	scanf("%d %I64d", &n, &k);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	int max=0;
	for (int i=0; i<n; i++) if(a[i]>max) max=a[i];
	printf("%d", max);

	int i=0, j=1;long long cnt=k;
	while (cnt--){
		if (a[i]==max) break;
		if (a[i]>a[j]){
		 	if(++j>=n) j=0;  
		}
		else if(a[i]<a[j]){
			i=j, j++;
			if (j>=n) j=0;
			cnt=k-1;
		}
		if (i==j) j++;
	}

	printf("%d\n", a[i]);
}
