#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	int ans=5;

	for (int i=2; i<=n; i++){
		ans += (i-1)*5+5;
		ans -= (i-1)*2+1;
		ans %= 45678;
	}
	printf("%d\n", ans);

}
