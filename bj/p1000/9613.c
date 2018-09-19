#include <stdio.h>

int gcd(int a, int b){
	return b?gcd(b, a%b):a;
}

int main(){
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int a[100];
		for (int i=0; i<n; i++) scanf("%d", &a[i]);

		long long ans=0;
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++)
				ans+=gcd(a[i],a[j]);
		
		printf("%lld\n", ans);
	}
}
