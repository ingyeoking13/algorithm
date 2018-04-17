#include <stdio.h>
#include <vector>

using namespace std;
struct pos{ int x, y, type; };
struct mymv{int dx, dy; };

vector<pos> cam;
vector<mymv> d[6]; 
int dir[8], a[8][8];
int mn =0x3f3f3f3f;

mymv pre(mymv now, int nowdir){

	if (nowdir ==0);
	else if ( nowdir == 1){
		int tmp = now.dy;
		now.dy =  -now.dx;
		now.dx = tmp;
	}
	else if ( nowdir == 2){
		now.dx = -now.dx;
		now.dy = -now.dy;
	}
	else {
		int tmp = now.dy;
		now.dy = now.dx;
		now.dx = -tmp;
	}
	return now;
}

void dfs(int now, int sz, int n, int m){
	if (now==sz){

		for (int i=0; i<sz; i++){
			pos now = cam[i];
			int nowdir = dir[i];
			for (int j=0; j<d[now.type].size(); j++){
				int x = now.x, y = now.y;

				mymv precalc = pre(d[now.type][j], nowdir);
				int xmove = precalc.dx;
				int ymove = precalc.dy;
//				printf("cma %d, type %d dir %d  %d %d %d %d\n", i, now.type, nowdir, x, y, xmove, ymove);
				x+=xmove, y+=ymove;

				while(0<= x && x< n && 0<= y && y < m){
					if (!a[x][y]) a[x][y]=7;
					else if (a[x][y]==6) break;
					x += xmove, y+= ymove;
				}
			}
		}

		/*
		printf("sz : %d\n", sz);
		for (int i=0; i<sz; i++){
			printf("%d %d ,", cam[i].x, cam[i].y);
		}
		printf("\n");
		for (int i=0; i<sz; i++){
			printf("%d ,", dir[i]);
		}

		printf("\n");

		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		*/

		int tmp=0;
		for (int i=0; i<n; i++ ){
			for (int j=0; j<m; j++){
				if (!a[i][j] ) tmp++;
				else if ( a[i][j] ==7 ) a[i][j]=0;
			}
		}
		mn = min(mn, tmp);
		return ;
	}

	for (int i=0; i<4; i++){
		dir[now]=i;
		dfs(now+1, sz, n, m);
	}

}

int main(){
	int n, m; scanf("%d %d", &n, &m);
	int cnt=0;

	d[1].push_back({0,1});
	d[2].push_back({0,1}); d[2].push_back({0,-1});
	d[3].push_back({-1,0}); d[3].push_back({0,1});
	d[4].push_back({0,1}); d[4].push_back({0,-1}); d[4].push_back({-1,0});
	d[5].push_back({-1,0}); d[5].push_back({0,1}); d[5].push_back({0,-1}); d[5].push_back({1, 0});

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &a[i][j]);
			if ( a[i][j]!=6  && a[i][j]!=0) cam.push_back({i, j, a[i][j]});
		}
	}
	dfs(0, cam.size(), n, m);

	printf("%d\n", mn);
}
