#include <stdio.h>

char a[101][101], b[101][101];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%s", a[i]);

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			b[i][j]=a[i][j];
	
	int ans=0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n-1; j++){
			if ( a[i][j]=='.' && a[i][j+1]=='.')  { 
				ans++; int now=j;
				while(now<n && a[i][now]=='.') a[i][now++]='X';
			}
		}
	}
	printf("%d ", ans);
	ans=0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n-1; j++){
			if ( b[j][i]=='.' && b[j+1][i]=='.')  { 
				ans++; int now=j;
				while(now<n && b[now][i]=='.') b[now++][i]='X';
			}
		}
	}
	printf("%d\n", ans);
}
