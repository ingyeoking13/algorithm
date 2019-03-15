#include <stdio.h>
#include <vector>
using namespace std;

typedef struct { int v, w; }node;
vector <node> a[100001];

int main(){
	int n, m; scanf("%d %d", &n, &m);
	for (int i=1; i<n-1; i++) a[i].push_back({i+1, 1});
	a[n-1].push_back({n, 100003 - n+2 });

	m-=(n-1);
	for (int l=2; l<=n && m; l++){
		for (int i=1; i<n && m; i++){
			a[i].push_back({i+l, 1});
			m--;
		}
	}

	for (int i=1; i<n; i++){
		for (int j=0; j< a[i].size(); j++){
			printf("%d %d %d\n", i, a[i][j].v, a[i][j].w);
		}
	}
}
