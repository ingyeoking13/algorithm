#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
int a[500][501], d[500][501], sum[501], mn[501];
int main(){
	int n, m, K; scanf("%d %d %d", &n, &m, &K);

	for (int i=0; i<n; i++){

		for (int j=1; j<=m; j++) scanf("%1d", &a[i][j]);
		for (int j=1; j<=m; j++) sum[j] = a[i][j]+sum[j-1]; 
		// sum[i] is total classes to i-hours

		for (int j=0; j<=K; j++) mn[j] = INF;
		//mn will hold min hours range while he skip classes(<= k)
		if ( sum[m] <= K)  mn[sum[m]]=0; 

		for (int j=1; j<=m; j++){
			for (int k=j; k<=m; k++){
				int s= sum[m] - sum[k] + sum[j-1]; 
				// s is skip counting
				if ( s<= K) mn[s] = min(mn[s], j-i+1);
				// if s <= k, 
				// then mn[s] will hold minimum of hours range that skip s classes
			}
		}

		for (int j=0; j<=K; j++) {
			for (int k=0; j+k <=K; k++){
				td[j+k] = min(td[j+k], d[j]+mn[k]);
			}
		}
		for (int j=0; j<=K; j++) d[j] = td[j];
	}

	int ans=INF;
	for (int i=0; i<=K; i++) ans = min(ans, d[i]);
	printf("%d\n", ans);

}
