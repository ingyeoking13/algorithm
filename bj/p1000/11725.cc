#include <bits/stdc++.h>

using namespace std;
vector<int> e[100001];
queue<int> q;
int p[100001];

int main(){
	int n; scanf("%d", &n);

	for (int i=0; i<n-1; i++){
		int a, b; 
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}

	q.push(1); p[1]=1;
	while(!q.empty()){
		int now = q.front(); 
		q.pop();
		for (int i=0; i<e[now].size(); i++){
			if ( !p[e[now][i]] ){
				q.push(e[now][i]);
				p[e[now][i]] = now;
			}
		}
	}
	for (int i=2; i<=n; i++) printf("%d\n", p[i]);
}
