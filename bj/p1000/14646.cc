#include <stdio.h>
#include <algorithm>

using namespace std;
char chk[200001];
int main(){
	int n; scanf("%d", &n);

	int ans=0, cur=0;
	for (int i=0; i<2*n; i++){
		int tmp; scanf("%d", &tmp);
		if ( chk[tmp] ) cur-=1;
		else {
			chk[tmp]=1, cur++;
			ans = max(cur, ans);
		}
	}
	printf("%d\n", ans);
}
