#include <stdio.h>
#include <algorithm>

using namespace std;

int mn;
void dfs(int now, int sum, int* cost, int* a){
	if ( now >= 12) {
		mn = min(mn, sum);
		return ;
	}

	if(a[now]){
		dfs(now+1, sum+cost[1], cost, a);
		dfs(now+1, sum+cost[0]*a[now], cost, a);
	}
	else dfs(now+1, sum, cost, a);
	dfs(now+3, sum+cost[2], cost, a);

};
int main(){
	int T; scanf("%d", &T);

	for (int t=1; t<=T; t++){

		int cost[4], a[12];
		for (int i=0; i<4; i++) scanf("%d", &cost[i]);
		for (int i=0; i<12; i++) scanf("%d", &a[i]);
		mn=cost[3];

		dfs(0, 0, cost, a);

		printf("#%d %d\n", t, mn);
	}

}
