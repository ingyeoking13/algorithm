#include <stdio.h>

int a[100][100], v[100][100], d[100][100];
int dx[4] ={ -1, 1, 0, 0};
int dy[4] ={ 0, 0, -1, 1};

int main(){
	int n; scanf("%d", &n);

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			scanf("%d", &a[i][j]);

	int cnt=0, q[10000], h, t;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if ( a[i][j] && v[i][j]==0 ){
				v[i][j]=++cnt;
				h=0, t=0;
				q[t++]=i*n+j;

				while(h<t){

					int now = q[h++];
					for (int k=0; k<4; k++){
						int nx = now/n+dx[k], ny = now%n+dy[k];
						if ( 0 <= nx && nx <n && 0<= ny && ny <n){
							if ( !v[nx][ny] && a[nx][ny] ){

								v[nx][ny]=cnt;
								q[t++]=nx*n+ny;

							}
						}
					}

				}

			}
		}
	}

	h=0, t=0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			d[i][j]=-1;
			if ( v[i][j] ) {
				q[t++]=i*n+j; 
				d[i][j]=0;
			}
		}
	}

	while(h<t){
		int now = q[h++];
		for (int k=0; k<4; k++){
			int nx = now/n + dx[k], ny = now%n + dy[k];
			if ( 0<= nx && nx <n && 0 <= ny && ny < n ){
				if ( d[nx][ny] == -1 ){
					q[t++]= nx*n+ny;
					d[nx][ny] = d[now/n][now%n]+1;
					v[nx][ny] = v[now/n][now%n];
				}
			}
		}
	}

	int ans= 1<<20;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			for (int k=0; k<4; k++){
				int nx = i+dx[k] , ny = j + dy[k];
				if ( 0<= nx && nx <n && 0 <=ny && ny< n){
					if ( v[i][j] != v[nx][ny] ){
						if ( ans > d[i][j]+d[nx][ny] ) 
							ans = d[i][j] +d[nx][ny];
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}
