#include <cstdio>
#include <cstring>

int d[501][501][3], n1, n2, n3; 
int dfs(int nowa, int nowb, int turn){
	if (d[nowa][nowb][turn]) return d[nowa][nowb][turn];

	int ball[3] = {n1, n2, n3};

	for (int i=0; i<3; i++){
		if (nowa-ball[i]>=0){
			if(dfs(nowa-ball[i], nowb, 3-turn)==turn){
				return d[nowa][nowb][turn] = turn;
			}
		}
	}
	for (int i=0; i<3; i++){
		if (nowb-ball[i]>=0){
			if(dfs(nowa, nowb-ball[i], 3-turn)==turn){
				return d[nowa][nowb][turn] = turn;
			}
		}
	}
	return d[nowa][nowb][turn] = 3-turn;
}

int main(){
	scanf("%d %d %d", &n1, &n2, &n3);
	for (int i=0; i<5; i++){
		memset(d, 0, sizeof(d));
		int a, b; scanf("%d %d", &a, &b);
		printf("%c\n", 'A'+dfs(a, b, 1)-1);
	}
}
