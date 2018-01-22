#include <stdio.h>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;
typedef struct { int v, w; }node;
vector<node> E[1001];
queue<node> q;

vector<int> dijikstra(int s){
	vector<node> d(1001, INF);
	vector<bool> v(1001, 0);
	d[s]=0, v[s]=1;

	while(1){
		for (int i=1; i<=1000; i++){
			if (d[i] <  && (!v[i]))
		}
	}
}

int main(){
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		E[u].push_back({v, w});
	}
	int s, e;
	scanf("%d %d", &s, &e);
	
	for (int i=0; i<=1000; i++){
		for (int j=0; j<E[i].size(); j++){
			printf("%d %d %d\n", i, E[i][j].v, E[i][j].w);
		}
	}

	vector<int> d = dijikstra(s);
	printf("%d\n", d[e]);

}
