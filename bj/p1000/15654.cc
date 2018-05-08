#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int a[8], chk[8], n, m;

void dfs(int step, vector<int> v){

	if ( step==m) {
		for (int i=0; i<v.size(); i++) printf("%d ", v[i]);
		printf("\n");
		return;
	}

	for (int i=0; i<n; i++){
		if(chk[i]) continue;
		v.push_back(a[i]);
		chk[i]=1; 
		dfs(step+1, v);
		chk[i]=0; 
		v.pop_back();
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	sort(a, a+n);
	vector<int> v;
	for (int i=0; i<n; i++){
		v.push_back(a[i]);
		chk[i]=1; 
		dfs(1, v);
		chk[i]=0; 
		v.pop_back();
	}
}
