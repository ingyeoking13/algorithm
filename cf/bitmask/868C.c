#include <stdio.h>

int a[16];
int main(){
	int n, k; scanf("%d %d", &n, &k);

	for (int i=0; i<n; i++){
		int state=0, x;
		for (int j=0; j<k; j++){
			scanf("%d", &x);
			state|=(x<<j);
		}
		a[state]++;
	}
	int ans=0;
	for (int i=0; i<(1<<k); i++){
		for (int j=0; j<(1<<k); j++){
			if ((i&j)==0 && a[i] && a[j]) ans=1;
		}
	}
	printf(ans?"YES\n":"NO\n");
}
