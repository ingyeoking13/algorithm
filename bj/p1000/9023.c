#include <stdio.h>
#include <string.h>

int cost, hotel, oneday;
int a[100], b[100], aLen, bLen;
int d[200][100][100][2][2];

int min(int x, int y)  { return x>y?y:x; }
int dfs(int n, int x, int y, int rx, int ry ){

	if ( x==aLen && y == bLen ) return 0;
  if ( n > aLen +bLen ) return 1<<25;
	if ( x > aLen ) return 1<<25;
	if ( y > bLen ) return 1<<25;

	if (d[n][x][y][rx][ry] >= 0) return d[n][x][y][rx][ry];

	d[n][x][y][rx][ry] = dfs(n+1, x+1, y, 0, 1) + (ry?oneday:hotel+oneday) + cost;
	d[n][x][y][rx][ry] = min( d[n][x][y][rx][ry], dfs(n+1, x, y+1, 1, 0) + (rx?oneday:hotel+oneday) + cost);	
  d[n][x][y][rx][ry] = min( d[n][x][y][rx][ry], dfs(n+1, x, y, 1, 1) + (rx?oneday:hotel+oneday) + (ry?oneday:hotel+oneday));
	d[n][x][y][rx][ry] = min( d[n][x][y][rx][ry], dfs(n+1, x+1, y+1, 0, 0) + ((a[x]==b[y])?cost:(2*cost))); 

	return d[n][x][y][rx][ry];
}

int main(){
	int T; scanf("%d", &T);
	while (T--){
		memset(d, -1, sizeof(d));
		scanf("%d %d %d", &cost, &hotel, &oneday);
		int i=0;
		while(1){
			scanf("%d", &a[i]);
			if (!a[i]) break;
			i++;
		}
		aLen=i, i=0;

		while(1){
			scanf("%d", &b[i]);
			if (!b[i]) break;
			i++;
		}
		bLen=i;

		printf("%d\n", dfs(0, 0, 0, 0, 0));
	}
}
