#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;
typedef struct _d{
	int no;
	int prior;
}DOCU;

int main(){

	int T, n, m, i;
	DOCU docu[100];
	int dis[100];
	queue<DOCU> que;
	scanf("%d", &T);

	while(T--){
		int j=0;
		scanf("%d %d", &n, &m);
		for (i=0; i<n; i++){
			scanf("%d", &docu[i].prior);
			docu[i].no=i;
			que.push(docu[i]);
		}

		while (!que.empty()){
			DOCU tmp;
			int max=0;
			for(i=0; i<n-j; i++){
				tmp=que.front();
				que.pop();
				if(max<tmp.prior) max=tmp.prior;
				que.push(tmp);
			}
			while(que.front().prior<max){
				tmp=que.front();
				que.pop();
				que.push(tmp);
			}
			j++;
			dis[que.front().no]=j;
			que.pop(); 
		}
		printf("%d\n", dis[m]);
	}
	return 0;
}
