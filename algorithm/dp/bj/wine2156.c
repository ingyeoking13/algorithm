#include <stdio.h>

int max(int a, int b){
	if (a>b) return a;
	return b;
}

int main(){
	int dp[10000][3], n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &dp[i][0]);

	dp[0][1] = dp[0][2] = dp[0][0]; 
	dp[1][1] = dp[1][0];
	dp[1][2] = dp[0][0]+dp[1][0];
	dp[0][0] = dp[1][0] = 0;


	for (int i=2; i<n; i++) {
		dp[i][2] = dp[i-1][1]+dp[i][0];
		dp[i][1] = max(max(max(dp[i-1][0]+dp[i][0], dp[i-2][0]+dp[i][0]),dp[i-2][1]+dp[i][0]),dp[i-2][2]+dp[i][0]);
		dp[i][0] = max(max(max(max(max(dp[i-1][0],dp[i-2][0]), dp[i-2][1]),dp[i-2][2]),dp[i-1][1]),dp[i-1][2]);

	}
	
	printf("%d\n", max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]));
}

