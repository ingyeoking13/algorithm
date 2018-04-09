#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

/*
* Time complexity: TODO
* Space complexity: TODO
*/

bool chk[100001];
int main(int argc, const char *argv[]) {
	int N;
	scanf("%d\n", &N);
	vector<int> v;
	vector<vector<int> > e;
	e.resize(100001);

	for (int i = 0; i < N; ++i) {
		int x, y; scanf("%d %d\n", &x, &y);

		if ( !chk[x] ) v.push_back(x), chk[x]=1;
		if ( !chk[y] ) v.push_back(y), chk[y]=1;
		e[x].push_back(y); e[y].push_back(x);
	}

	memset(chk, 0, sizeof(chk));
	int ans=0;

	for (int i=0; i<v.size(); i++){
		if ( chk[v[i]] ) continue;

		queue<int> q;
		chk[v[i]]=1;
		q.push(v[i]);

		while(!q.empty()){
			int now = q.front(); q.pop();
			
			for (int j=0; j<e[now].size(); j++){
				if ( chk[e[now][j]] ) continue;
				chk[e[now][j]]=1;
				q.push(e[now][j]);
			}
		}
		ans++;

	}

	printf("%d\n", ans);
	return 0;
}

