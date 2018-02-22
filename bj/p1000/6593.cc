#include <bits/stdc++.h>

using namespace std;
vector<int> e[30*30*30];
int d[30*30*30]; char s[30][30][31];
int dx[6]= {-1, 1, 0, 0, 0, 0};
int dy[6]= { 0, 0, -1, 1, 0, 0};
int dh[6]= { 0, 0, 0, 0, 1, -1};
priority_queue<pair<int, int> > pq;
int main(){
	while(1){
		int h, row, col, S, E;
		scanf("%d %d %d", &h, &row, &col);
		if ( h*row*col ==0 ) break;

		for (int i=0; i<h; i++){
			for (int j=0; j<row; j++){
				scanf("%s", s[i][j]);
				for (int k=0; k<col; k++){
					if ( s[i][j][k] == 'S') S=i*row*col+j*col+k;
					if ( s[i][j][k] == 'E') E=i*row*col+j*col+k;
					e[i*row*col+j*col+k].clear();
				}
			}
		}

		for (int i=0; i<h; i++){
			for (int j=0; j<row; j++){
				for (int k=0; k<col; k++){

					for (int l=0; l<6; l++){
						int nx = j+dx[l], ny = k+dy[l] , nh = i+dh[l];
						if (0 <= nx && nx < row && 0 <= ny && ny < col && 
								0 <= nh && nh < h){
							if ( s[nh][nx][ny] == '.'|| s[nh][nx][ny]=='E'){
								e[i*row*col+j*col+k].push_back(nh*row*col+nx*col+ny);
							}
						}
					}
					d[i*row*col+j*col+k]=30*30*30+1;
				}
			}
		}

		d[S]=0; pq.push({0, S});

		while(!pq.empty()){
			int cost = -pq.top().first;
			int now = pq.top().second;
			pq.pop();
			if( d[now] <cost) continue;

			for (int i=0; i<e[now].size(); i++){
				if ( d[e[now][i]] > d[now]+1 ){
					d[e[now][i]] = d[now]+1;
					pq.push({-d[e[now][i]], e[now][i] });
				}
			}
		}
		if(d[E] == 30*30*30+1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", d[E]);
	}
}
