#include <stdio.h>
char a[12][6];
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, -1, 1}, cnt=0;

void chkdfs(int x, int y, char c){
	cnt++;
	if (cnt==4) return;

	for (int i=0; i<4; i++){
		int nx= x+dx[i], ny=y+dy[i];
		if (nx>=0 && ny>=0 && nx<12 && ny<6){
			if (a[nx][ny]==c){ 
				a[x][y]='*';
				chkdfs(nx, ny, c);
				a[x][y]=c;
			}
		}
	}
};

void dfs(int now, char c){
	int x= now/6, y= now%6;
	a[x][y]='.';
	for (int i=0; i<4; i++){
		int nx= x+dx[i], ny=y+dy[i];
		if (nx>=0 && ny>=0 && nx<12 && ny<6){
			if (a[nx][ny]==c) {
				dfs(nx*6+ny, c);
			}
		}
	}
};

int main(){
	for (int i=0; i<12; i++) scanf("%s", a[i]); 
	int change=1, ans=0;

	while(change){
		change=0;
		for (int i=0; i<12; i++){
			for (int j=0; j<6; j++){
				if (a[i][j]!='.') chkdfs(i,j, a[i][j]);
				if (cnt>=4) { dfs(i*6+j, a[i][j]); change=1;}
				cnt=0;
			}
		}

		for (int i=10; i>=0; i--){
			for (int j=0; j<6; j++){
				int now=i;
				while(now+1<12 && a[now+1][j]=='.'){
					char tmp=a[now][j];
					a[now][j]='.';
					a[now+1][j]=tmp;
					now++;
				}
			}
		}
		if (change) ans++;
	}
	printf("%d\n", ans);
}
