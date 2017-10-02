#include <stdio.h>

int arr[1000000];
int main(){
	int n, a, b, c; 
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d",  &arr[i]);
	scanf("%d %d", &b, &c);

	long long ans=0;
	for (int i=0; i<n; i++){
 		arr[i]-=b; ans++;
		if (arr[i]>0) {
			long long x= arr[i]/c;
			long long remain= arr[i]%c;
			if (remain) ans += x+1;
			else ans+=x;
		}
	}

	printf("%lld\n", ans);
}
