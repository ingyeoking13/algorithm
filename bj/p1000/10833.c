#include <stdio.h>

int main(){

	int n; scanf("%d", &n);
	int ans=0;
	while(n--){
		int a, b; scanf("%d %d", &a, &b);
		ans+=b%a;
	}
	printf("%d\n", ans);
}
