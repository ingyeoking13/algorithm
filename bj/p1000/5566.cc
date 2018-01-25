#include <bits/stdc++.h>

int a[1001];
int main(){
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	int now=0, ans=0, tmp;
	for (int i=0; i<m; i++){
	 	scanf("%d", &tmp);
		now+=tmp;
		if(now < n-1 && a[now]) now+=a[now]; 
		if (now >= n-1) {
			ans=i+1;
			break;
		}
	}

	printf("%d\n", ans);

}
