#include <cstdio>
#include <queue>
int main(){

  using namespace std;
	int seek, hide;
	int check[100001]={0}, dis[100001]={0}; 
	queue<int> que;

	scanf("%d %d", &seek, &hide);

	que.push(seek);
	check[seek]=1;
	dis[seek]=0;
	while(!que.empty() && !check[hide]){
		int now = que.front();
		que.pop();
		if(now-1>=0 && !check[now-1]){
			que.push(now-1);
			check[now-1]=1;
			dis[now-1]=dis[now]+1;
		}
		if(now+1<=100000 && !check[now+1]){
			que.push(now+1);
			check[now+1]=1;
			dis[now+1]=dis[now]+1;
		}
		if(2*now<=100000 && !check[2*now]){
			que.push(2*now);
			check[2*now]=1;
			dis[2*now]=dis[now]+1;
		}
	}

	printf("%d\n", dis[hide]);
	return 0;

}
