#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
int d[100000][3][21], n, k;
char s[100000][2];

bool win( char c, int st){
	if ( c == 'R' ) return st==2;
	if ( c == 'S' ) return st==0;
	if ( c == 'P' ) return st==1;
}

int dfs(int now, int cnt, int st){
	if (now==n){
		if (win(s[now][0], st)) return d[now][st][cnt]=1; 
		else return d[now][st][cnt]=0;
	}
	if ( cnt > k) return d[now][st][cnt]=0;

	if ( d[now][st][cnt] >=0 ) return d[now][st][cnt];

	int my = d[now][st][cnt]=win(s[now][0], st);
	int tmp = dfs(now+1, cnt, st);
	tmp = max(tmp, dfs(now+1, cnt+1, (st+1)%3));
	tmp = max(tmp, dfs(now+1, cnt+1, (st+2)%3));

	return d[now][st][cnt]=my+tmp;
}

int main(){

	scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++) scanf("%s", s[i]);

	memset(d, -1, sizeof(d));
	printf("%d\n", max(max(dfs(0, 0, 0), dfs(0, 0, 1)),dfs(0, 0,2)));
}
