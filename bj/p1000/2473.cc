#include <bits/stdc++.h>

using namespace std;
int a[5000];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	sort(a, a+n);
	long long mn = 1LL<<50;
	int q, w, e;

	for (int i=0; i<n; i++){

		int l = i+1, r=n-1;
		while( l<r ){
			long long tmp = (long long)a[i]+a[l]+a[r];
			if ( abs(mn) > abs(tmp)) {
				mn = tmp;
				q=i, w=l, e=r;

			}

			if (tmp >0) r--;
			else if ( tmp<0 ) l++;
			else { q=i, w=l, e=r; l++, r--; }
		}
	}

	printf("%d %d %d\n", a[q], a[w], a[e]);
}
