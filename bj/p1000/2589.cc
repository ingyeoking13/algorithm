#include <bits/stdc++.h>

using namespace std;
char a[50][51];
int d[2500][2500], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
vector<int> e[2500];

int main(){

	int row, col; scanf("%d %d", &row, &col);
	for (int i=0; i<row; i++) scanf("%s", a[i]); 

	for (int i=0; i<row*col; i++) for (int j=0; j<row*col; j++) d[i][j]=1<<20;

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if (a[i][j]=='L'){
				int now = i*col+j;
				d[now][now]=0;
				for (int k=0; k<4; k++){
					if ( 0<= i+dx[k] && i+dx[k] <row && 0<= j+dy[k] && j+dy[k]<col){
						if ( a[i+dx[k]][j+dy[k]]=='L' ){
							e[now].push_back((i+dx[k])*col+j+dy[k]);
							e[(i+dx[k])*col+j+dy[k]].push_back(now);
						}
					}
				}
			}
		}
	}

	for (int i=0; i<row*col; i++){
		if ( a[i/col][i%col] != 'W'){
			priority_queue<int> pq; 
			pq.push(i); 

			while(!pq.empty()){
				int now= pq.top(); pq.pop();
				for (int j=0; j< e[now].size(); j++){
					if ( d[i][e[now][j]] >d[i][now]+1 ){
						d[i][e[now][j]] = d[i][now]+1;
						pq.push(e[now][j]);
					}
				}
			}
		}
	}

	int ans=0;
	for (int i=0; i<row*col; i++){
		for (int j=0; j<col*row; j++){
			if (ans<d[i][j] && d[i][j]!=1<<20) ans=d[i][j];
		}
	}

	printf("%d\n", ans);
}
