#include <stdio.h>

long long zcy[100001];
int len(long long n){
	int ret=0;
	while(n){ n/=10; ret++; }
	return ret;
}
long long myfunc(long long n){
	int l=len(n);
	long long s=n, d=0;
	for (int i=0; i<l; i++){
		d*=10; d+=s%10; 
		s/=10; n*=10;
	}
	return n+d;
}
int main(){
	int k, p; scanf("%d %d", &k, &p);
	for (long long i=1; i<=k; i++) zcy[i-1]=myfunc(i);
	long long ans=0;
	for (int i=0; i<k; i++) {
		ans+=zcy[i];
		ans%=p;
	}
	printf("%lld\n", ans);
}
