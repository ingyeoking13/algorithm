#include <stdio.h>

int main(){
	int comp[101];
	int chk[101][101];
	int n, i, j, link;
	scanf("%d", &n);
	scanf("%d", &link);

	for(i=0; i<101;i++) comp[i]=0;
	for(i=0; i<101; i++){
		for(j=0; j<101; j++){
			chk[i][j]=0;
		}
	}

	comp[1]=1;
	for(i=0; i<link; i++){
		int pc1, pc2;
		scanf("%d %d", &pc1, &pc2);
		chk[pc1][pc2]=1;
		chk[pc2][pc1]=1;
	}
	for (i=1; i<=n;i++){
		for (j=1; j<=n; j++){
			if (chk[i][j] || chk[j][i]) {
				comp[i] |=comp[j];
				comp[j] |=comp[i];
			}
		}
	}
	int ans=0;
	for(i=2;i<=n;i++)
		ans+=comp[i];
	printf("%d\n", ans);
	return 0;
}
