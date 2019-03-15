#include <stdio.h>

int n, a[3][6], chk[100];
int main(){
	scanf("%d", &n);

	for (int i=0; i<n; i++)
	 	for (int j=0; j<6; j++) 
			scanf("%d", &a[i][j]);

	for (int i=0; i<n; i++){
		for (int j=0; j<6; j++){
			chk[a[i][j]]=1;
			for (int k=0; k<n; k++){
				if (k==i) continue;
				for (int l=0; l<6; l++){
					chk[a[i][j]*10+a[k][l]]=1;
				}
			}
		}
	}
	int ans;
	for (int i=1; i<100; i++) if(!chk[i]) {ans=i; break;}
	printf("%d", ans-1);
}
