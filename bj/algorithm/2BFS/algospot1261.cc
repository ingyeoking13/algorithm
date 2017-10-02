#include <cstdio>
#include <queue> 

using namespace std;
int arr[200], dist[200];
int dx[4]= {0, 0, -1, 1};
int dy[4]= {-1, 1, 0, 0};

int main(){

	int m, n;
	scanf("%d %d", &m, &n);

	for(int x=0; x<n; x++){
		for (int y=0; y<m; y++){
			scanf("%1d", &arr[x*m+y]);
			dist[x*m+y]=-1;
		}
	}

	queue<int> que;
	queue<int> postque;

	que.push(0);
	dist[0]=0;
	while(!que.empty()){
		int now=que.front();
		que.pop();
		for (int i=0;i<4; i++){
			int x=now/m, y=now%m;
			int nx=x+dx[i], ny=y+dy[i];

			if (nx>=0 && nx<n && ny >=0 && ny <m){
				if (dist[nx*m+ny]==-1){
					if (!arr[nx*m+ny]){
						dist[nx*m+ny]= dist[now];
						que.push(nx*m+ny);
					}else{
						dist[nx*m+ny] = dist[now]+1; 
						postque.push(nx*m+ny);
					}
				}
			}
		}
		if(que.empty()){
			while(!postque.empty()){
				que.push(postque.front());
				postque.pop();
			}
		}
	}
	printf("%d\n", dist[n*m-1]);
	return 0;
}
