#include <stdio.h>

int d[31]={1};
int main(){
	int n;
	scanf("%d", &n);
	for (int i=2; i<=n; i+=2){
		d[i]=3*d[i-2];
		for (int j=0; j<=i-4;j+=2){
			d[i]+=d[j]*2;
		}
	}

	printf("%d\n", d[n]);
}
