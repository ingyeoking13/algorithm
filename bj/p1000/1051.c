#include <stdio.h>

int a[51][51];
int main(){

	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%1d", &a[i][j]);
		}
	}

	int ans=1, max= n>m?m:n;
	for (int len=1; len<max; len++){
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				if (i+len < n && j+len < m)
					if (a[i][j]==a[i+len][j] && 
							a[i+len][j] == a[i][j+len] && 
							a[i+len][j] == a[i+len][j+len])
						ans=(len+1)*(len+1);
			}
		}
	}
	printf("%d\n", ans);
}
