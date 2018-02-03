#include <bits/stdc++.h>

using namespace std;
typedef struct { int v; char c; }node;
int d[101][101][3][27];
vector<node> e[101];

int dfs(int i, int j, int turn, char al){
	if (d[i][j][turn][al-'a']) return d[i][j][turn][al-'a'];

	if (turn & 1){
		int sz=e[i].size();
		for (int k=0; k<sz; k++){
			if ( e[i][k].c >= al ){
				if( dfs(e[i][k].v, j, 3-turn, e[i][k].c)==1 ){
					d[i][j][turn][al-'a']=1;
				}
			}
		}
		if(!d[i][j][turn][al-'a']) d[i][j][turn][al-'a']=2;
	}
	else{
		int sz=e[j].size();
		for (int k=0; k<sz; k++){
			if ( e[j][k].c >= al ){
				if( dfs(i, e[j][k].v, 3-turn, e[j][k].c)==2 ){
					d[i][j][turn][al-'a']=2;
				}
			}
		}
		if(!d[i][j][turn][al-'a']) d[i][j][turn][al-'a']=1;
	}
	return d[i][j][turn][al-'a'];
}

int main(){
	int n, m; scanf("%d %d", &n, &m);
	while(m--){
		int u, v; char c[2]; scanf("%d %d %s", &u, &v, c);
		e[u].push_back({v, c[0]});
	}

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			printf("%c", 'A'+dfs(i, j, 1, 'a')-1);
		}
		printf("\n");
	}
}
