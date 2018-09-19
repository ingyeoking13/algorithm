#include <stdio.h>

int a[2][5], b[2][5];
int max(int x, int y) { return x<y?y:x; }
int min(int x, int y) { return x<y?x:y; }
int main(){
	int n; scanf("%d", &n);

	int ans=0, ans2=900001;
	for (int i=1; i<2; i++) 
		for (int j=0; j<5; j++) 
			b[i][j]=900001;
	b[0][0] = 900001, b[0][4] = 900001;

	for (int i=1; i<=n; i++){
		for (int j=1; j<=3; j++){
			scanf("%d", &a[i%2][j]);

			b[i%2][j] = a[i%2][j];

			a[i%2][j] =max( 
								 max(a[(i-1)%2][j-1], a[(i-1)%2][j])
								 , a[(i-1)%2][j+1])+a[i%2][j];

			b[i%2][j] =min( 
								 min(b[(i-1)%2][j-1], b[(i-1)%2][j])
								 , b[(i-1)%2][j+1])+b[i%2][j];

			if ( i==n ){
				ans=max(a[i%2][j], ans);
				ans2=min(b[i%2][j], ans2);
			}
		}
	}

	printf("%d %d\n",ans, ans2);
}
