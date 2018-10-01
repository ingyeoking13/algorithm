#include <cstdio>
#include <queue>

int chk[1000001];
int dis[1000001];
using namespace std;
int main(){
	int max, start, dest, U, D;
	int i;
	queue<int> que;
	scanf("%d %d %d %d %d", &max, &start, &dest, &U, &D);

	chk[start]=1;
	dis[start]=0;
	que.push(start);
	while(!que.empty()){
		int now = que.front();
		que.pop();
		if (now+U<=max && !chk[now+U]){
			int next = now+U;
			chk[next]=1;
			que.push(next);
			dis[next] = dis[now]+1;
		}
		if (now-D>=1 && !chk[now-D]){
			int next = now-D;
			chk[next]=1;
			que.push(next);
			dis[next] = dis[now]+1;
		}
	}

	if(chk[dest]) printf("%d\n", dis[dest]);
	else printf("use the stairs\n");

	return 0;
}
