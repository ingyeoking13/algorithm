#include <stdio.h>
#include <algorithm>

using namespace std;
int cnt[1001];
int main(){
	int n, m; scanf("%d %d", &n, &m);
	while(m--){
		int row;
		scanf("%d", &row);
		cnt[row]++;
	}
	int ans=1e9;
	for (int i=1; i<=n; i++) ans = min(cnt[i], ans);
	printf("%d\n", ans);

}
