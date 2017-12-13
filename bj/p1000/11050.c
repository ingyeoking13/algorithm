#include <stdio.h>

int c[11][11];
int main(){

	int n, k; scanf("%d %d", &n, &k);

	c[0][0]=1;
	for (int i=1; i<=10; i++){
		for (int j=0; j<=i; j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}	
	printf("%d\n", c[n][k]);
}
