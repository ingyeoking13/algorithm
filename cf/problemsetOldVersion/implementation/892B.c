#include <stdio.h>

int a[1000000];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]); 

	int knife=n, ans=0;
	for (int i=n-1; i>=0; i--){
		if (knife>i) ans++;
		knife=knife>(i-a[i])?i-a[i]:knife;
	}
	printf("%d\n", ans);
}
