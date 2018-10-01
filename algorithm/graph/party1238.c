#include <stdio.h>

int d[1001][1001];
int main(){
	int v, e, n;
	scanf("%d %d %d", &v, &e, &n);
	int a, b, tmp;
	for (int i=1; i<=v; i++){
		for (int j=1; j<=v; j++){
			if (i!=j) d[i][j]= 1000001;
		}
	}

	for (int i=0; i<e; i++){
		scanf("%d %d %d", &a, &b, &tmp);
		if (d[a][b]>tmp)	d[a][b]=tmp;
	}

	for (int k=1; k<=v; k++){
		for (int i=1; i<=v; i++){
			for (int j=1; j<=v; j++){
				if (d[i][j]> d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
	int ans =0;

	for (int i=1; i<=v; i++){
		ans= d[i][n]+d[n][i]>ans?d[i][n]+d[n][i]:ans;
	}
	printf("%d\n", ans);
}
