#include <stdio.h>
#include <algorithm>

using namespace std;
int d[1000][1000][3], a[1000][1000];
int dx[] = {0, -1}, dy[] ={-1, 0};
int st[3] = {2, 0, 1};
int main(){
	int n; scanf("%d", &n);

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			scanf("%d", &a[i][j]);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){

			int x =i, y=j;
			if ( a[x][y] == 0 ) d[x][y][0] = 1;
			for (int k=0; k<2; k++){
				int px = x+ dx[k], py = y+dy[k];
				if ( 0<= px && 0<=py ){
					if ( d[px][py][st[a[x][y]]] > 0 ){
						d[x][y][a[x][y]] =
							max(d[x][y][a[x][y]], d[px][py][st[a[x][y]]]+1);
					}
					for (int l = 0; l<3; l++)
						d[x][y][l]=max(d[x][y][l], d[px][py][l]);
				}
			}
		}
	}

	int ans =0;
	for (int i=0; i<3; i++) ans = max(ans, d[n-1][n-1][i]);
	printf("%d\n",ans);

}
