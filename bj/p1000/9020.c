#include <stdio.h>

int p[10001];
int main(){

	for (int i=2; i<=10000; i++){
		if ( !p[i] ){
			for (int j=i*2; j<=10000; j+=i) p[j]=1;
		}
	}

	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d", &n);
		for (int i=n/2; i>=0; i--){
			if ( !p[i] && !p[n-i] ) {
				printf("%d %d\n", i, n-i);
				break;
			}
		}
	}
}
