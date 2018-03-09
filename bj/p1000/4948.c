#include <stdio.h>

int p[123456*2+1]={1, 1};
int main(){

	for (int i=2; i<123456*2+1; i++){
		if (!p[i]){
			for (int j=i*2; j<123456*2+1; j+=i){
				p[j]=1;
			}
		}
	}

	while(1){
		int n; scanf("%d", &n);
		if (!n) break;

		int ans=0;
		for (int i=n+1; i<=2*n; i++){
			if ( !p[i] ) ans++;
		}
		printf("%d\n", ans);
	}

}
