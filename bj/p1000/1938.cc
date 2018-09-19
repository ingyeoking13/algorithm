#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
char s[50][51];
int dx[]={-1, 1, 0, 0}, dy[] ={0, 0, -1, 1};
int dist[50][50][2];
struct pos{int x, y, dir;};
pos p[50][50][2];

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%s", s[i]);

	vector<pos> v, t;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if ( s[i][j] =='B') v.push_back({i, j,0});
			else if (s[i][j]=='E') t.push_back({i,j,0});
		}
	}

	pos sts=v[1], ends=t[1];
	if (v[1].x == v[0].x) sts.dir=0;
	else sts.dir=1;

	if (t[1].x == t[0].x) ends.dir=0;
	else ends.dir=1;

	queue<pos> q;
	q.push(sts);
	dist[sts.x][sts.y][sts.dir]=1;
	memset(p, -1, sizeof(p));

	while(!q.empty()){
		pos now = q.front(); q.pop();

		for (int i=0; i<4; i++){
			pos tmp = now;
			tmp.x += dx[i], tmp.y += dy[i];
			int x = tmp.x, y = tmp.y, d = tmp.dir;

			if (0<= x && x <n && 0<=y &&  y <n){
				if ( 0<= x+d && x+d <n&&  0<=x-d && x-d<n){
					if ( 0<=y+(1-d) && y+(1-d) <n && 0<=y+(d-1) && y+(d-1) <n){
						if ( s[x][y] =='1'|| s[x-d][y+(1-d)] =='1' || s[x+d][y+(d-1)] == '1' ) continue;
						if ( !dist[x][y][d] ){
							q.push(tmp);
							dist[x][y][d]=dist[now.x][now.y][now.dir]+1;
							p[x][y][d] ={now.x,now.y,now.dir};
						}
					}
				}
			}
		}

		int chk=1;
		for (int i=-1; i<=1; i++){
			for (int j=-1; j<=1; j++){
				if ( now.x +i <0 || now.x +i >= n || now.y +j <0 || now.y +j >= n){
					chk=0; break;
				}
				if ( s[now.x+i][now.y+j]=='1') {chk=0; break;}
			}
		}

		if (chk){
			if (dist[now.x][now.y][1-now.dir] ) continue;
			dist[now.x][now.y][1-now.dir] = dist[now.x][now.y][now.dir]+1;
			p[now.x][now.y][1-now.dir] ={now.x,now.y,now.dir};
			q.push({now.x, now.y, 1-now.dir});
		}
	}

	/*
	int curx =ends.x, cury = ends.y , curd = ends.dir;
	while(curx!=-1){
		printf("%d %d %d\n", curx, cury, curd);
		pos next=p[curx][cury][curd];
		curx= next.x, cury = next.y, curd = next.dir;
	}
	*/
	if ( dist[ends.x][ends.y][ends.dir]) printf("%d\n", dist[ends.x][ends.y][ends.dir]-1);
	else printf("0\n");
}
