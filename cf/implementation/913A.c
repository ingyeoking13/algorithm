#include <stdio.h>

int main(){
	int n, m; 
	scanf("%d %d", &n, &m);
	int ans=0;
	for (int i=0; m && i<n; i++){
		ans |= m%2<<i;
		m/=2;
	}
	printf("%d\n", ans);
}
