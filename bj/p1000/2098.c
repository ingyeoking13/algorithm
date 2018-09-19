#include <stdio.h>
int w[17][17], d[1<<17][17];
int min(int x, int y) {return x<y?x:y;}
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &w[i][j]);
		}
	}
	for (int i=0; i< (1<<n) ; i++ ) 
		for (int j=0; j<n; j++)
			d[i][j]=1<<25;

	d[1][0]=0;
	for (int i=3;i<(1<<n); i++){
		for (int j=1; j<n; j++){
			if (i&(1<<j)){
				for (int k=0; k<n; k++){
					if (k!=j && (i&(1<<k))  && w[k][j]){ 
						d[i][j]=min(d[i][j], d[i-(1<<j)][k]+w[k][j]);
					}
				}
			}
		}
	}

	int ans=1<<25;
	for (int i=1; i<n; i++){
		ans= min(ans, d[(1<<n)-1][i]+w[i][0]);
	}
	printf("%d\n", ans);
}
