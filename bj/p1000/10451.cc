#include <vector>
#include <stdio.h>

using namespace std;

int v[1001];
vector <int> e[1001];

void dfs(int now){
	v[now]=1;
	if(!v[e[now][0]]) 
		return dfs(e[now][0]);
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d", &n);

		for (int i=1; i<=n; i++){
			e[i].clear(); v[i]=0;
		}

		for (int i=1; i<=n; i++){
			int tmp; scanf("%d", &tmp);
			e[i].push_back(tmp);
		}

		int cnt=0;
		for (int i=1; i<=n; i++){
			if (!v[i]) {
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

}
