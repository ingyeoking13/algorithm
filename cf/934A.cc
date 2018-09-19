#include <bits/stdc++.h>

using namespace std;
long long a[51], b[51];
int main(){
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) scanf("%lld", &a[i]);
	for (int i=0; i<m; i++) scanf("%lld", &b[i]);

	long long maxn = -(1LL<<60);
	int hidden=0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if ( a[i]*b[j] > maxn ){
			 	maxn=a[i]*b[j];
				hidden=i;
			}
		}
	}

	maxn = -(1LL<<60);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if ( a[i]*b[j] > maxn && i!=hidden ){
			 	maxn=a[i]*b[j];
			}
		}
	}
	printf("%lld\n", maxn);
}
