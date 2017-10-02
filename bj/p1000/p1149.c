#include <stdio.h>

int a[1000][3];
int d[1000][3];
int min(int a, int b){
	if (a<b) return a;
	return b;
}

int main(){
	int n;
	scanf("%d", &n);

	for (int i=0; i<n; i++)
		for (int j=0; j<3; j++)
			scanf("%d", &a[i][j]);
		

	d[0][0]=a[0][0]; d[0][1]=a[0][1]; d[0][2]=a[0][2];

	for (int i=1; i<n;i++){
		d[i][0]=min(d[i-1][1]+a[i][0],d[i-1][2]+a[i][0]);
		d[i][1]=min(d[i-1][0]+a[i][1],d[i-1][2]+a[i][1]);
		d[i][2]=min(d[i-1][0]+a[i][2],d[i-1][1]+a[i][2]);
	}

	printf("%d\n", min(min( d[n-1][0], d[n-1][1]),d[n-1][2]));
}
