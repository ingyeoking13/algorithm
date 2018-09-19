//greedy? dp? dp!
#include <stdio.h>

int w[1001], v[1001], d[1001][1001], t[1001][1001];
int max(int a, int b){ if(a>b) return a; return b;}
int main(){

	int n, max;
	scanf("%d %d", &n, &max);
	for (int i=0; i<n; i++) scanf("%d %d", &w[i], &v[i]);

	for (int i=0; i<n; i++){
		d[i][i]=v[i]; t[i][i]=w[i];
		for (int j=i; j<n; j++){
			for (int k=i; k<j; k++){
				d[i][j]=max(max(d[k][j],d[i][j]),);
			}
		}
	}

	int ans=0;
	for (int i=0; i<n; i++) {
		if (t[i]<=max){
			ans=ans>d[i]?ans:d[i];
		}
	}

	printf("%d\n", ans);
}
