#include <bits/stdc++.h>
int a[100000];
int sum[100000];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		sum[i] += sum[i-1]+a[i];
	}
	long long ans=0;
	for (int i=0; i<n; i++) ans += (sum[i]- a[i]) * a[i]; 
	printf("%lld\n",ans);
}
