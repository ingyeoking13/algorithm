#include <stdio.h>

int r, c;
char RC[20][20];
int chk[26];
int dx[4]={ 0, 0, -1, 1};
int dy[4]={ -1, 1, 0, 0};

int bfs(int rc, int cnt){
	int ans=0;
	int x = rc/c, y = rc%c;
	for (int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if (nx >=0 && nx < r && ny >= 0 && ny < c){
			if (!chk[RC[nx][ny]-'A']) {
				chk[RC[nx][ny]-'A']=1;
				rc = nx*c+ ny;
				int next = bfs(rc, cnt+1);
				if (ans< next) ans= next;
				chk[RC[nx][ny]-'A']=0;
			}
		}
	}
	return ans+1;
}
int main(){

	scanf("%d %d", &r, &c);

	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			scanf(" %c", &RC[i][j]);

  chk[RC[0][0]-'A']=1;

	printf("%d\n", bfs(0,0));

}
