#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
int main(){
	queue<int> que;
  int testcase, a, b;
	int chk[10001]={0}, dis[10001]={0}, from[10001]={0};
	char how[10001]={'\0'}, ans[10001]={'\0'};
	scanf("%d", &testcase);

	while(testcase--){
		scanf("%d %d", &a, &b);
		que.push(a);
		memset(chk,0, sizeof(chk));
		memset(dis,0, sizeof(dis));
		chk[a]=1;
		from[a]=-1;
		while(!que.empty()){
			int now = que.front();
			que.pop();
			int next = (now*2)%10000;
			if(!chk[next]){
				que.push(next);
				chk[next]=1;
				dis[next]= dis[now]+1;
				from[next] = now;
				how[next] = 'D';
			}
			next = now-1;
			if (next<0) next=9999;
			if(!chk[next]){
				que.push(next);
				chk[next]=1;
				dis[next] = dis[now]+1;
				from[next] = now;
				how[next] = 'S';
			}
			next = now/1000 + now%1000*10; 
			if(!chk[next]){
				que.push(next);
				chk[next]=1;
				dis[next] = dis[now]+1;
				from[next] = now;
				how[next] = 'L';
			}
			next = now%10*1000 + now/10; 
			if(!chk[next]){
				que.push(next);
				chk[next]=1;
				dis[next] = dis[now]+1;
				from[next] = now;
				how[next] = 'R';
			}
		}

		int i=0;
		while(b!=a){
 		ans[i++]=how[b];
			b=from[b];
		}

		for(;i--;)
			printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}
