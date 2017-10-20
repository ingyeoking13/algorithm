#include <stdio.h>

int max(int a, int b){ if (a>b) return a; return b; }
int main(){
	int d[1000][1000], n, m;
	scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &d[i][j]);
		}
	}

	int ans=0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (i==0 && j==0);
			else if (i==0){
				d[i][j]= d[i][j-1]+d[i][j];
			}
			else if (j==0){
				d[i][j]= d[i-1][j]+d[i][j];
			}
		  else{
			  d[i][j]= max(max(d[i-1][j],d[i-1][j-1]),d[i][j-1])+d[i][j];
		  }
		}
	}
	printf("%d\n", d[n-1][m-1]);
}
