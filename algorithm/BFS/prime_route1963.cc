#include <cstdio>
#include <cstring>
#include <queue>

int change(int num, int index, int digit){

	int s[4], i;
	if(index==0 && digit==0) return -1;
	s[0] =num/1000;
	s[1] =num/100%10;
	s[2] =num/10%10; 
	s[3] =num%10;
	s[index] = digit;
	num = 0;
	for (i=0; i<4;i++){
		if (i==0) num +=s[i]*1000;
		else if (i==1) num +=s[i] *100;
		else if (i==2) num +=s[i] * 10;
		else num+=s[i];
	}
	return num;
}
int main(){

  using namespace std;
	queue<int> que;
	int i, j, n, m, testcase;
	int chk[10000]={0}, dis[10000]={0}, prime[10000]={0};

	for (i=1000; i<=10000; i++){
		for (j=2;j*j<=i;j++){
			if(i%j==0) prime[i]=1;
		}
	}

	scanf("%d", &testcase);

	while(testcase--){
		scanf("%d %d", &n, &m);
		que.push(n);
		memset(chk, 0, sizeof(chk));
		memset(dis, 0, sizeof(dis));
		dis[n]=0;
		chk[n]=1;
		while(!que.empty()){
			int now = que.front();
			que.pop();
			for (i=0; i<4; i++){
				for (j=0; j<=9; j++){
					int next = change(now, i, j);
					if (next != -1){
						if (!prime[next] && !chk[next]){
							que.push(next);
							dis[next] = dis[now]+1;
							chk[next] = 1;
						}
					}
				}
			}
		}
		printf("%d\n", dis[m]);
	}
}
