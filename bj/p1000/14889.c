#include <stdio.h>

int n, r, a[21][21];
int c[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, chk[21];
int comb(){
	int i=r-1;
	while (i>=0 && c[i]==n-r+i) i--;
	if (i<0) return 0;
	c[i]++;
	for (int j=i+1; j<r; j++) c[j]=c[i]+j-i;
	return 1;
}
int main(){
	scanf("%d", &n);
	r=n/2; 
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	int ans=1<<20;
	do{
		int tmp=0, tmp2=0;
		for (int i=1; i<=n; i++) chk[i]=0;
		for (int i=0; i<n/2; i++) chk[c[i]]=1;

		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if (chk[i] && chk[j]) tmp+=a[i][j];
				else if (chk[i]==0 && chk[j]==0) tmp2+=a[i][j];
			}
		}

		tmp = tmp2-tmp;
		if (tmp<0) tmp=-tmp;
		if (ans>tmp) ans=tmp;
	}while(comb());

	printf("%d\n", ans);
}
