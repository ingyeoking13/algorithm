#include <stdio.h>

int main(){

	int T;
	scanf("%d", &T);
	while(T--){
		int ans=0;
		int n;
		scanf("%d", &n);
		for(int i=5; i<=n; i*=5){
			ans+=n/i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
