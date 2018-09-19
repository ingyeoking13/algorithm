#include <bits/stdc++.h>

using namespace std;
int a[100];
int main(){
	int n, m; scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	sort(a, a+n);

	int ans=0;

	for (int i=0; i<n; i++){
		int cnt=1;

		for (int j = i+1; j<n; j++){
			if ( a[j]-a[i] <= m ) cnt++;
			else break;
		}

		if ( cnt> ans) ans=cnt;
	}

	printf("%d\n",n-ans);
}
