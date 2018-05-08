#include <stdio.h>
#include <vector>

using namespace std;
vector<int> chk;
vector<int> e[100];

long long a[101];
int n, ans[100];

int dfs(int now, int step){
	ans[step]=now;

	if (step == n-1) {
		for (int i=0; i<n; i++) printf("%lld ", a[ans[i]]);
		printf("\n");
		return 1;
	}

	int sz = e[now].size();
	for (int i=0; i<sz; i++){

		if (chk[e[now][i]]) continue;
		chk[e[now][i]]=1;
		if(dfs(e[now][i], step+1)) return 1;
		chk[e[now][i]]=0;

	}
	return 0;
}


int main(){
	 scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%lld", &a[i]);
	chk.resize(100);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (i==j) continue;

			if (a[i]*2 == a[j]) e[i].push_back(j);
			if ((a[i]%3 == 0) && (a[i]/3 == a[j])) e[i].push_back(j);
		}
	}

	for (int i=0; i<n; i++){
		chk[i]=1;
		if(dfs(i, 0)) break;
		chk[i]=0;
	}
	
}
