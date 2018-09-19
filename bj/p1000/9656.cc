#include <bits/stdc++.h>

int d[1001];
int main(){
	int n; scanf("%d", &n);

	d[0]=1;
	for (int i=1; i<=n; i++){
		if ( i-1 >=0 && !d[i-1]) d[i]=1;
		if ( i-3 >=0 && !d[i-3]) d[i]=1;
	}
	printf(d[n]?"SK\n":"CY\n");
}
