#include <stdio.h>

long long d[31][31];
int main(){
	int T;
	scanf("%d", &T);
	for (int i=1; i<=30; i++) d[1][i]=i;

	for (int i=2; i<=30; i++){
		for (int j=i; j<=30; j++){
			for (int k=j-1; k>=i-1; k--){
				d[i][j]+=d[i-1][k];
			}
		}
	}

	while(T--){
		int m, n;
		scanf("%d %d", &m, &n);
		printf("%lld\n", d[m][n]);
	}
}
