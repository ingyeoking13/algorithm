#include <cstdio>

int a[20][20];
int dx[4] ={-1, 1, 1, 0};
int dy[4] ={1, 0, 1, 1};

int chk(int x, int y, int d){
	int now=a[x][y];
	if ( a[x-dx[d]][y-dy[d]] == now) return 0;
	for (int i=1; i<=5; i++){
		if ( a[x][y] != now) return 0;
		x+=dx[d]; y+=dy[d];
	}
	return a[x][y]!=now;
}

int main(){
	for (int i=0; i<19; i++) 
		for (int j=0; j<19; j++)
			scanf("%d", &a[i][j]);

	for (int i=0; i<19; i++){
		for (int j=0; j<19; j++){
			if (a[i][j]){
				for (int k=0; k<4; k++){
					if (chk(i, j, k)) return !printf("%d\n%d %d\n", a[i][j], i+1, j+1);
				}
			}
		}
	}
	printf("0\n");
}
