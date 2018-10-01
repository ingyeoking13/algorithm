#include <stdio.h>


long long d[101]={0, 1, 1, 1, 2, 2};
int main(){

	for (int i=6; i<=100; i++){
		d[i]= d[i-5] + d[i-1];
	}
	int T; scanf("%d", &T);
	for (int t=1; t<=T; t++){
		int n; scanf("%d", &n);

		printf("#%d %lld\n",t, d[n]);
	}
}
