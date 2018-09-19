#include <stdio.h>
#include <queue>

using namespace std;
int a[100][100], s[100][100], d[100][100];
int row, col;
int q[10000], h, t;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
priority_queue<pair<int, int> > pq;

void fill(int now, int dist){
	int x = now/col, y = now%col;
	a[x][y]=-1;
	d[x][y]=dist;
	pq.push({-dist,x*col+y});

	for (int i=0; i<4; i++){
		int nx = x+dx[i], ny =y+dy[i];
		if ( 0<= nx && nx < row && 0 <= ny&& ny< col){
			if (!a[nx][ny]){
				fill(nx*col+ny, dist);
			}
		}
	}	
}

int main(){
	scanf("%d %d", &row, &col);

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			scanf("%d", &a[i][j]);
		}
	}

	fill(0, 0);

	while(!pq.empty()){
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		int x = now/col, y= now%col;

		for (int i=0; i<4; i++){
			int nx = x+dx[i], ny = y+dy[i];
			if (0 <= nx&& nx<row && 0<=ny && ny<col){
				if ( a[nx][ny] == 1){
				 	s[nx][ny]++;
					if ( s[nx][ny] >1 ) {
						a[nx][ny]=-1;
						d[nx][ny]=d[x][y]+1;
						pq.push({-d[nx][ny], nx*col+ny});
					}
				}
				else if (!a[nx][ny]){
					fill(nx*col+ny, d[x][y]);
				}
			}
		}
		/*
		for (int i=0; i<row; i++){
			for (int j=0; j<col; j++){
				printf("%d ", d[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
	}

	int ans=0;
	for (int i=0; i<row; i++) 
		for (int j=0; j<col; j++) 
			if (ans < d[i][j]) ans=d[i][j];
	printf("%d\n", ans);
}
