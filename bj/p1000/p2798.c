#include <stdio.h> 
int a[101], d[101][4];
int n, obj;
int max( int a, int b){ if (a>b) return a; return b; }

int main(){

	scanf("%d %d", &n, &obj);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	d[0][1]=a[0]; d[1][1]=a[1]; d[1][2]=a[0]+a[1];

	for (int i=2; i<n; i++ ){
		d[i][1]=a[i]; 
		for (int j=0; j<i; j++){
			if(d[j][1]+a[i]<=obj) d[i][2]=max(d[j][1]+a[i],d[i][2]);
			if(d[j][2]+a[i]<=obj) d[i][3]=max(d[j][2]+a[i],d[i][3]);
		}
	}

	int ans=0;
	for (int i=0; i<n; i++) ans=max(ans,d[i][3]);
	printf("%d\n", ans);
}
