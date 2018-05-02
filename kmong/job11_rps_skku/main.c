#include <stdio.h>
#include <string.h>

int dp[100000][3][21];

int max(int a, int b) { return a>b?a:b;}

int ok(char c, int state){
	if ( c == 'R' ) {
		if (state==2) return 1;
	}
	if ( c == 'S' ) {
		if (state==0) return 1;
	}
	if ( c == 'P' ){
		if (state==1) return 1;
	}
	return 0;
}

int go(int now, int cnt, int state,int n, int k, char input[100000][2]){

	if (now==n){
		if (ok(input[now][0], state)){
			return dp[now][state][cnt]=1; 
		}
		else {
			return dp[now][state][cnt]=0;
		}
	}

	if ( cnt > k) { // if change is over k
		return dp[now][state][cnt]=0;
	}

	if ( dp[now][state][cnt] >=0 ) return dp[now][state][cnt];

	dp[now][state][cnt]=ok(input[now][0], state);
	int tmp = go(now+1, cnt, state,n, k, input);
	tmp = max(tmp, go(now+1, cnt+1, (state+1)%3, n, k, input));
	tmp = max(tmp, go(now+1, cnt+1, (state+2)%3, n, k, input));

	return dp[now][state][cnt]+=tmp;
}

int main(){

	int n, k;
	char input[100000][2];

	scanf("%d %d", &n, &k);

	for (int i=0; i<n; i++) {
		scanf("%s", input[i]);
	}

	memset(dp, 0xff, sizeof(dp));
	int ans = go(0, 0, 0, n, k, input);
	ans = max(ans,go(0, 0, 1,n, k, input));
	ans = max(ans,go(0, 0, 2,n, k, input));

	printf("%d\n", ans);
}
