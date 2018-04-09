#include <stdio.h>
#include <queue>

using namespace std;
int dist[200001];
queue<int> q;
int main(){
	int n, k; scanf("%d %d", &n, &k);

	q.push(n);
	dist[n]=1;
	while(!q.empty()){
		int now = q.front(); q.pop();

		int tmp=now;
		while( tmp*2 <= 200000 && !dist[tmp*2] ){
			dist[tmp*2] = dist[now];
			q.push(tmp*2);
			tmp*=2;
		}
		if ( now+1 <= 200000 && !dist[now+1]){
			dist[now+1]=dist[now]+1;
			q.push(now+1);
		}
		if ( now-1 >= 0 && !dist[now-1]){
			dist[now-1]=dist[now]+1;
			q.push(now-1);
		}
	}
	printf("%d\n", dist[k]-1);
}
