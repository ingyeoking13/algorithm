#include <bits/stdc++.h>

using namespace std;

vector<int> e[1001];
queue<int> q;
int d[1001], result[1000], len;

int main(){
	int n, m; scanf("%d %d", &n,&m);
	while(m--){
		int k; scanf("%d", &k);
		int before; scanf("%d", &before);

		for (int i=1; i<k; i++){
			int now;
			scanf("%d", &now);
			e[before].push_back(now);
			d[now]++;
			before=now;
		}
	}

	for (int i=n; i>=1; i--) if (!d[i]) q.push(i);

	while(!q.empty()){
		int now = q.front(); q.pop();
		if (!d[now]){ result[len++] = now; } 

		int sz = e[now].size();
		for (int i=0; i<sz; i++){
			d[e[now][i]]--;
			if ( !d[e[now][i]] ) q.push(e[now][i]);
		}
	}

	if (len == n) for (int i=0; i<len; i++) printf("%d ", result[i]);
	else printf("0");
	printf("\n");

}
