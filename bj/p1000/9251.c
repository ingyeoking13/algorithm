#include <stdio.h>
#include <string.h>

char s[1002], s2[1002];
int d[2][1001];
int max(int x, int y){ return x<y?y:x;}
int main(){
	scanf("%s %s", s+1, s2+1);

	int n = strlen(s+1);
	int m = strlen(s2+1);

	int ans=0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if ( s[i]==s2[j] ) d[i%2][j]=d[(i-1)%2][j-1]+1;
			else{
				d[i%2][j] =  max(d[i%2][j-1],d[(i-1)%2][j]);
			}
			if ( ans< d[i%2][j] ) ans=d[i%2][j];
		}
	}

	printf("%d\n", ans);
}
