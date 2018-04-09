#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int n, m, mx, a[6], len;
int swap(int &a, int &b) {int tmp=b; b=a, a=tmp;}
int mk(int* a){
	int ret=0;
	for (int i=len-1; i>=0; i--){ ret*=10; ret+=a[i]; }
	return ret;
}

void dfs(int now, int cnt){

	if (cnt == m){
		int sum=mk(a);
		mx =max(mx, sum);
		return; 
	}
	if (cnt > m) return;
	if (now ==len) return;

	int chk=0;
	for (int i=0; i<len; i++){
		if (i==now) continue;
		int cur = mk(a);
		swap(a[now], a[i]);
		int next = mk(a);

		if (cur<=next) {
			chk=1;
			dfs(i, cnt+1);
		}
		swap(a[i],a[now]);
	}
	if (!chk && 
	dfs(now+1, cnt);
};

int main(){
	int T; scanf("%d", &T);

	for (int t=1; t<=T; t++){
		scanf("%d %d", &n, &m); 
		memset(a, -1, sizeof(a));
		len=0, mx=0;

		for (int i=n; i; i/=10) a[len++] = i%10; 

		dfs(0, 0);
		printf("#%d %d\n", t, mx);
	}
}
