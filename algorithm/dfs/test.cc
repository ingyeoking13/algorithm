#include <stdio.h>
#include <vector>

using namespace std;

bool chk[101];
vector<int> e[101];

void dfs(int now){
	chk[now]=1;

	for (int i=0; i<e[now].size(); i++){
		if ( chk[e[now][i]] ) continue;
		dfs(e[now][i]);
	}

}
int main(){
	int vtx= 100;

	for (int i=1; i<=vtx; i++){
		if ( chk[i] ) continue;
		dfs(i);
	}

}

