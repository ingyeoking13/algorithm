#include <stdio.h>

int d[100000]={0};
int min(int a, int b){ if (a<b) return a; return b;}
int main(){
	int n;
	scanf("%d", &n);
	for (int i=1;i<=n;i++){
		d[i]=i;
		for(int j=1; j*j<=i; j++){
			d[i]=min(d[i-j*j]+1,d[i]);
		}
	}
	printf("%d\n", d[n]);
}
