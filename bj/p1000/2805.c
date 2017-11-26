#include <stdio.h>

int a[1000000];
int main(){
	int n, m; scanf("%d %d", &n, &m);
	int max=0;
	for (int i=0; i<n; i++){
	 	scanf("%d", &a[i]);
		if (max<a[i]) max=a[i];
	}

	int l=0, r=max;
	while (l<=r){
		int mid= (l+r)/2;
		long long sum= 0;
		for (int i=0; i<n; i++) 
			if (mid<a[i]) sum+=a[i]-mid;

		if (sum<m) r=mid-1; 
		else l= mid+1;
	}
	printf("%d\n", r);
}
