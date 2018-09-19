#include <bits/stdc++.h>

using namespace std;
typedef struct{ int v; char c; }pos;
vector<pos> e[101];
int main(){
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++){
		pos tmp;
		int u;
		scanf("%d %d %c", &u, &tmp.v, &tmp.c);
		e[u].push_back(tmp);
	}


}
