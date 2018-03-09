#include <stdio.h>

long long d[1000]= {0, 1};
long long s[1000]= {0, 1};
int n;

int dfs(int now, long long sum){
	if ( sum == n ) return 1; 
	if ( now < 0 ) return 0;

	if ( n-sum <= s[now] ){
		if (dfs(now-1, sum+d[now])){ 
				printf("%lld ", d[now]);
				return 1;
		}
		if (dfs(now-1, sum)) return 1;
	}

	return 0;

}

int main(){

	int len=0;
	for (int i=2; i<1000; i++){
		d[i] = d[i-1] + d[i-2];
		s[i] = s[i-1] + d[i];
		if ( d[i] > 0x3f3f3f3f ) { len =i; break; }
	}

	int T; scanf("%d", &T);
	while(T--){
		scanf("%d", &n);

		int i;
		for (i=0; i<len; i++) {
			if ( d[i] >= n ) break;
		}

		dfs(i, 0);
		printf("\n");
	}
}
