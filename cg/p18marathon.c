//fail.........
#include <stdio.h>


int a[101][101], d[101][101][11], chk[101][101];
int main(){
	int T;
	scanf("%d", &T);
	for (int test_case=1; test_case<=T; test_case++){
		int row, col, w;
		scanf("%d %d %d", &col, &row, &w);

		for (int i=0; i<=row; i++){
			for (int j=0; j<=col; j++){
				scanf("%d", &a[i][j]);
				if (a[i][j]<0) {
					chk[i][j]=1;
					a[i][j]=-a[i][j];
				}
			}
		}


		int k=0;
		for (int i=row; i>=0; i--){
			for (int j=0; j<=col; j++){
				if (j==0 && i==row) d[i][j][k]=0;
				else if (i==row){ 
					d[i][j][k]=d[i][j-1][k]+abs(a[i][j],a[i][j-1]);
				}
				else if (j==0){
					d[i][j][k]=d[i-1][j][k]+abs(a[i][j],a[i-1][j]);
				}
				else{
					d[i][j][k]=min(d[i-1][j][k]+abs(a[i][j], a[i-1][j]), d[i][j-1][k]+abs(a[i][j],a[i-1][j]));
				}
				if (chk[i][j]){
					d[i][j][k+1]=d[i][j][k];
					k++;
				}
			}
		}
		int ans=0;
		for (int i=0; i<=11; i++){
			ans

		}

		printf("Case #%d\n%d\n", test_case, ans);

	}
}
