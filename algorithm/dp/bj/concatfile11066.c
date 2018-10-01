#include <stdio.h>
int T, d[501][501], in[501], s[501];
int min(int a, int b){ if (a>b) return b; return a; }
int main(){
	scanf("%d", &T); 	
	while(T--){
		int n;
		scanf("%d", &n);
		for (int i=1; i<=n; i++)  {scanf("%d", &in[i]); s[i]=s[i-1]+in[i];}

		for (int i=1;i<n;i++){
			for(int j=1;j+i<=n; j++){
				d[j][j+i]=1<<30;
				for (int k=j;k<i+j;k++){
					d[j][j+i]=min(d[j][k]+d[k+1][j+i]+s[i+j]-s[j-1],d[j][j+i]);
					
				}
			}
		}

		printf("%d\n", d[1][n]); 
	}
}
