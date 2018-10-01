#include <stdio.h>

using namespace std;
long long psum[100001];
int main(){

	int T; scanf("%d", &T);
	while(T--){
		int n, m, k; scanf("%d %d %d", &n, &m, &k);
		for (int i=1; i<=n; i++) scanf("%d", &a[i]);

		psum[1]=a[1];
		for (int i=1; i<n; i++) psum[i]= psum[i-1]+a[i];

		int cnt=0;

		for (int i=k; i<n+k; i++){
			if (psum[i] - psum[i-k]


		}





	}



}
