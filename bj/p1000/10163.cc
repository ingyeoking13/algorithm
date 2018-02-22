#include <cstdio>

int b[103][103], v[103][103];
int dx[4]={-1, 1, 0, 0}, dy[4] ={0 ,0, -1, 1};

int dfs(int x, int y, int col){
	int ret=1;

	for (int i=0; i<4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if (0<= nx && nx <= 100 && 0<= ny && ny<= 100){
			if ( b[nx][ny]==col && !v[nx][ny] ){
				v[nx][ny]=1; ret+=dfs(nx, ny, col);
			}
		}
	}
	return ret;
}

int main(){
	int n; scanf("%d", &n);

	for (int i=1; i<=n; i++){
		int sx, sy, width, height;
		scanf("%d %d %d %d", &sx, &sy, &width, &height);
		for (int x=sx; x<sx+width; x++){
			for (int y=sy; y<sy+height; y++){
				b[x][y]=i;
			}
		}
	}

	for (int i=1; i<=n; i++){
		int width=0;
		for (int x=0; x<=100; x++){
			for (int y=0; y<=100; y++){
				if (b[x][y]== i) width++;
				/*
				if (b[x][y]==i && !v[x][y]) {
					v[x][y]=1;
					width+=dfs(x, y, b[x][y]);
				}
				*/
			}
		}
		printf("%d\n", width);
	}
}
