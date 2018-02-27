#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n, k, a, b; 
	scanf("%lld %lld %lld %lld", &n,
			&k, &a, &b);

	long long ans=0;

	while(n!=1){

		if ( n%k == 0){
			if ((n-n/k)*a > b) ans+=b, n/=k;
			else ans+=a*(n-1), n=1;
		}
		else ans+=(n%k)*a, n=n-n%k;
		if (n==0) ans-=a, n++;
	}

	printf("%lld\n", ans);
}
