#include <stdio.h>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;
map<int ,int> d;
map<int, int> pos;
int p[200001],a[200001];
void dfs(int now){
	if (now == -1) return;
	dfs(p[now]);
	printf("%d ", now);
}

int main(){
	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}

	memset(p, -1, sizeof(p));

	int mx=1, end=1;
	for (int i=1; i<=n; i++) {
		auto idx = d.find(a[i]-1);
		pos[a[i]]=i;

		if ( idx == d.end()) d[a[i]]=1;
		else {
			d[a[i]] = d[a[i]-1]+1;
			p[i] = pos[a[i]-1];
			if ( d[a[i]] > mx) end=i, mx=d[a[i]];
		}
	}

	printf("%d\n", mx);
	dfs(end);
	printf("\n");
}
