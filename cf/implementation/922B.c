#include <stdio.h>

int main(){
	int n; scanf("%d", &n);

	int ans=0;
	for (int i=1; i<=n; i++){
		for (int j=i+1; j<=n; j++){
			for (int k=j+1; k<=n; k++){
				if ( (i^j^k )== 0) {
					if ( k> i+j) {
						printf("%d %d %d : %d\n", i, j, k, i^j^k); 
						ans++;
					}
				}
			}
		}
	}
	printf("%d\n", ans);

}
