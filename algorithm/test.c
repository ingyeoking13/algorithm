#include <stdio.h>

int a[300], d[300][3];
int max(int a, int b) { if (a>b) return a; return b;}
int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]); 

	d[0][1]=a[0];
	d[1][1]=a[1];
	d[1][2]=a[1]+a[0];
	for (int i=2; i<n; i++){
		d[i][1]=max(d[i-2][2]+a[i], d[i-2][1]+a[i]);
		d[i][2]=d[i-1][1]+a[i];
	}

	printf("%d\n", max(d[n-1][1],d[n-1][2]));

}
