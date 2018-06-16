#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a>b?a:b; }
char s[501];
int d[501][501], len;

int dfs(int f, int t)
{
	printf("%d %d\n", f , t);
	if (f>t) return 0;
	if (f+1 == t) {
		return ((s[f] == 'a' && s[t] == 't' ) || (s[f] == 'g' && s[t] == 'c'))*2;
	}
	if ( d[f][t] ) return d[f][t];
	if ((s[f] == 'a' && s[t] == 't') ||
			(s[f] == 'g' && s[t] == 'c'))
	{
		return d[f][t]= dfs(f+1, t-1)+2;
	}
	return d[f][t]= max(dfs(f+1, t) , dfs(f, t-1));
}

int main()
{
	scanf("%s", s);
	len = strlen(s);
	printf("%d\n",dfs(0, len-1));
}
