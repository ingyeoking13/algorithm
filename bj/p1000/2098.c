#include <stdio.h>

int w[16][16], d[1<<16][16];
int min(int x, int y) {return x<y?x:y;}

int main(){
	int n; 
  scanf("%d", &n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &w[i][j]);
		}
	}

	for (int i=0; i< (1<<n) ; i++ ) 
		for (int j=0; j<n; j++)
			d[i][j]=1<<25;

  //for (int i=0; i<n; i++) d[1<<i][i] = 0;

  d[1][0] = 0;

	for (int i=1; i<(1<<n); i++){ // state
		for (int j=1; j<n; j++){ // lately visited
			if ( i & (1<<j) ){
				for (int k=0; k<n; k++){ // search 
					if ( k!=j && (i&(1<<k)) && w[k][j]>0 ){ 
						d[i][j] = min(d[i][j], d[i-(1<<j)][k] + w[k][j]);
					}
				}
			}
		}
	}

	int ans=1e9;
	for (int i=0; i<n; i++){
    if ( w[i][0] ) ans = min(ans, d[(1<<n)-1][i] + w[i][0]);
	}
	printf("%d\n", ans);
}
