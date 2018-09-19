#include <stdio.h>

int a[10000];
int main(){
	int k, n, max=0;
	scanf("%d %d",&k, &n);
	for (int i=0; i<k; i++){
		scanf("%d", &a[i]);
		if (max<a[i]) max=a[i];
	}

	int l=0, r=max, ans=0;
	while(l<=r){

		int mid= (l+r)/2+(l+r)%2;
		long long sum=0;
		for (int i=0; i<k; i++){
			sum += (long long)a[i]/mid;
		}
		if ( sum < n ) r = mid-1;
		else {
			if ( ans<mid ) ans=mid;
			l= mid+1;
		}
	}

	printf("%d\n", ans);
}
