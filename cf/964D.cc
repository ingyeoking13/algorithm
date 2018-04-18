#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int d[200001], tmp[200001];
bool chk[200001];
vector<int> e[200001];
int main(){

	int n; scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int v; scanf("%d", &v);
		if (v){
			e[i].push_back(v);
			e[v].push_back(i);
			d[v]++, d[i]++;
		}
	}

	vector<int> cand;
	for (int i=1; i<=n; i++){
		if (d[i]%2==0){
			cand.push_back(i);
		}
	}
	for (int i=1; i<=n; i++ ) tmp[i]=d[i];

	for (int i=0; i<cand.size(); i++){
		for (int j=1; j<=n; j++ ) d[i]=tmp[i];
		queue<int> q;
		q.push(cand[i]);

		vector<int> ans;
		while(!q.empty()){
			int now = q.front(); q.pop();
			if (chk[now]) continue;
			inq[now]=0;

			if (d[now]%2==0) {
				ans.push_back(now);
				chk[now]=1;
			}

			for (int i=0; i<e[now].size(); i++){
				d[e[now][i]]--;
				if (d[e[now][i]]%2==0){ 
					q.push(e[now][i]);
					inq[e[now][i]]=1;
				}
			}

			for (int i=1; i<=n; i++) {
				if (d[i]%2==0) q.push(i);
			}
		}

		if (ans.size() == n) {
			printf("YES\n");
			for (int i=0; i<n; i++) {
				printf("%d\n", ans[i]);
			}
			return 0;
		}
	}
	printf("NO\n");
}
