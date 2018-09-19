#include <stdio.h>

int d[100000][2], a[100000][2];
int max(int x, int y) { return x<y?y:x;}
int main(){
	int T; scanf("%d", &T);

	while(T--){
		int n; scanf("%d", &n);

		for (int i=0; i<n; i++) scanf("%d", &a[i][0]);
		for (int i=0; i<n; i++) scanf("%d", &a[i][1]);


		d[0][0]=a[0][0], d[0][1] =a[0][1];
		for (int i=1; i<n; i++){
			d[i][0]=d[i][1]=0;
			d[i][0]+=d[i-1][1]+a[i][0];
			d[i][1]+=d[i-1][0]+a[i][1];
			if ( i-2>=0) {
				d[i][0] = max(d[i][0], d[i-2][0]+a[i][0]);
				d[i][0] = max(d[i][0], d[i-2][1]+a[i][0]);
				d[i][1] = max(d[i][1], d[i-2][0]+a[i][1]);
				d[i][1] = max(d[i][1], d[i-2][1]+a[i][1]);
			}
		};

		printf("%d\n", max(d[n-1][0],d[n-1][1]));

	}

}
