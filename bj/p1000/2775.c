#include <stdio.h>

int a[15][15];
int main(){

	for (int i=0; i<=14; i++) a[0][i]=i;
	for (int i=1; i<=14; i++){
		for (int j=0; j<=14; j++){
			for (int k=0; k<=j; k++){
				a[i][j]+=a[i-1][k];
			}
		}
	}

	int T; scanf("%d", &T);
	while(T--){
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d\n", a[n][k]);
	}
}
