#include <stdio.h>

long long d[105]={1, 1, 1, 2, 2};
int main(){
	for (int i=5; i<105;i++) d[i]=d[i-1]+d[i-5];
	int T, n;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		printf("%lld\n", d[n-1]);
	}
}
