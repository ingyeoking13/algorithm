#include <bits/stdc++.h>

using namespace std;
typedef struct{ int x, y, sec; bool type; }pos;
vector<pair<int, int>> fire;

int dx[4] = {-1, 1, 0, 0}, dy[4] ={0, 0, 1, -1};
int v[1000][1000];
char a[1001][1001];

int main(){
	int T; scanf("%d", &T);
	while(T--){

		memset(a, 0, sizeof(a));
		memset(v, 0, sizeof(v));
		fire.clear();
		int col, row; scanf("%d %d", &col, &row);
		int sx, sy;

		for (int i=0; i<row; i++){
			scanf("%s", a[i]);
			int len= strlen(a[i]);
			for (int j=0; j<col; j++) {
				if (a[i][j] == '@')  sx=i, sy=j; 
				if (a[i][j] == '*')  fire.push_back({i, j});
			}
		}

		v[sx][sy]=1;
		queue<pos> q;
		for (int i=0; i<fire.size(); i++) 
			q.push({fire[i].first, fire[i].second, 0, 0});

		q.push({sx, sy, 0, 1});
		int ans=0;

		while(!q.empty()){
			pos now = q.front(); q.pop();

			int x = now.x, y = now.y, sec = now.sec;
		  bool type = now.type;

			if ( type && ( x==0 || x == row-1 || y ==0 || y== col-1 ))  {
				 ans=printf("%d\n", sec+1);
				 break;
			}

			for (int i=0; i<4; i++){
				int nx = x + dx[i], ny = y + dy[i];
				if ( 0 <= nx && nx < row && 0 <= ny && ny < col ) {
					if (a[nx][ny] != '#' && a[nx][ny] != '*'){
						if (!v[nx][ny] ){
							if (type) v[nx][ny]=1, a[nx][ny]= '@';
							else a[nx][ny] = '*';
							q.push({nx, ny, sec+1, type});
						}
					}
				}
			}
		}
		if (!ans) printf("IMPOSSIBLE\n");
	}
}
