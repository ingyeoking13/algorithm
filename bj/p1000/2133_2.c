#include <stdio.h>

long long d[31][8];
int main(){
	int n; scanf("%d", &n);
	d[0][7]=1;
	for (int i=1; i<=n; i++){
		d[i][0] = d[i-1][7];
		d[i][1] = d[i-1][6];
		d[i][2] = d[i-1][5];
		d[i][3] = d[i-1][4] + d[i-1][7];
		d[i][4] = d[i-1][3];
		d[i][5] = d[i-1][2];
		d[i][6] = d[i-1][1] + d[i-1][7];
		d[i][7] = d[i-1][0] + d[i-1][3] + d[i-1][6];
	}
	printf("%lld\n", d[n][7]);
}
