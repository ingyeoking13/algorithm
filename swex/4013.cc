#include <stdio.h>
#include <string.h>

using namespace std;

int a[4][8];
int chk[4], move[4];
int ans;
int ret(int a){
	if (a<0){
		while(a<0) a+=8;
		return a;
	}
	return a%8;
}

void dfs (int now, int dir){
	chk[now]=1;
	int ndir=0;

	if (now+1<4){
		ndir = a[now][ret(2-move[now])]==a[now+1][ret(6-move[now+1])];
		if (ndir==0) {
			ndir = (-1)*dir;
			if(!chk[now+1]) dfs(now+1,ndir);
		}
	}

	if (now-1>=0){
		ndir = a[now][ret(6-move[now])]==a[now-1][ret(2-move[now-1])];
		if (ndir==0) {
			ndir = (-1)*dir;
			if(!chk[now-1]) dfs(now-1, ndir);
		}
	}

	if (dir>0)  move[now]++;
	else move[now]--;

}

int main(){
	freopen("in.in", "r", stdin);
	int T; scanf("%d", &T);

	for (int t=1; t<=T; t++){
		int k; scanf("%d", &k); // total move

		memset(move, 0, sizeof(move)); //wheel's move information
		ans=0;

		for (int i=0; i<4; i++) {
			for (int j=0; j<8; j++){
				scanf("%d", &a[i][j]);
			}
		}

		while(k--){
			int s, dir;

			memset(chk, 0, sizeof(chk));
			scanf("%d %d", &s, &dir);
			dfs(s-1, dir);

			for (int i=0; i<4; i++){
//				printf("%d'th wheel:", i);
				for (int j=0; j<8; j++){
//				printf("%d ", a[i][ret(j-move[i])]);
				}
//				printf("\n");
			}

		}
		for (int i=0; i<4; i++){
			if (a[i][ret(-move[i])] ==1) {

				if (i ==0 ) ans+=1;
				else if (i == 1) ans+=2; 
				else if (i == 2) ans+=4; 
				else if (i == 3) ans+=8; 
			}
		}
		printf("#%d %d\n", t, ans);

	}
}
