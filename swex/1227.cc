/* 100*100 사이즈에서 dfs 탐색은 불가능할 거라 판단하였음
	 (연산량이 많다고 고려.)
	 queue 를 이용한 탐색을 활용해 d 배열을 채워넣는 것으로 구현하였음 
 */
#include <stdio.h>
#include <string.h>
#include <queue>
#define N 100

using namespace std;
char s[100][101];
int d[100][100];
int dx[] ={-1, 1, 0, 0}, dy[] ={0, 0, -1, 1};
struct pos{ int x, y;};

int main(){
	int t=0;
	while(t!=10){
		scanf("%d", &t);

		for (int i=0; i<N; i++) scanf("%s", s[i]);
		memset(d,0, sizeof(d));

		int sx, sy, ex, ey;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				if (s[i][j] =='2' ) sx=i, sy=j;
				else if (s[i][j] =='3') ex=i, ey=j;
			}
		}
		d[sx][sy]=1;
		queue<pos> q;
		q.push({sx, sy});

		while(!q.empty()) {
			pos now =q.front();  q.pop();
			int x= now.x, y = now.y;

			for (int i=0; i<4; i++){
				int nx = x+dx[i], ny = y+dy[i];
				if (0<= nx  && nx < N && 0<=ny && ny<N ){
					if (s[nx][ny] !='1'  && !d[nx][ny]){
						d[nx][ny]=1;
						q.push({nx,ny});
					}
				}
			}
		}
		printf("#%d %d\n", d[ex][ey]);
	}
}
