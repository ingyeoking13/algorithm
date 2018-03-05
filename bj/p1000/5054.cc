#include <bits/stdc++.h>

using namespace std;
int a[20];
int main(){
	int T; scanf("%d", &T);

	while(T--){
		int n; scanf("%d", &n);
		for (int i=0; i<n; i++){
			scanf("%d", &a[i]);
		}

		sort(a, a+n);

		int l=0, r= n-1;
		int ans=98765432;
		for (int i=0; i<n; i++){
			int tmp=(abs(a[i]-a[l]) + abs(a[i]-a[r]))*2;
			if ( ans > tmp) ans=tmp;
		}
		printf("%d\n", ans);

	}
}
