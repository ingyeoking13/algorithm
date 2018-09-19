#include <stdio.h>
#define mod 9901

int d[100001][3];
int main(){

	d[0][0]=1, d[0][1]=1, d[0][2]=1;
	int n;
	scanf("%d", &n);

	for (int i=1; i<100001; i++){
		d[i][0]=d[i-1][1]%mod+d[i-1][0]%mod+d[i-1][2]%mod;
		d[i][1]=d[i-1][0]%mod+d[i-1][2]%mod;
		d[i][2]=d[i-1][0]%mod+d[i-1][1]%mod;
	}

	printf("%d\n", (d[n-1][0]%mod+d[n-1][1]%mod+d[n-1][2]%mod)%mod);
}
