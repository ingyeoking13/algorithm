#include <stdio.h>

int a[101][101];
typedef struct { int x, y; char d; }robot;
int main(){

	int row, col, n, m;
	scanf("%d %d %d %d", &row, &col, &n, &m);

	robot r[101];
	for (int i=0; i<n; i++){
		scanf("%d %d %c", r[i].x, r[i].y, r[i].c);
		a[r[i].x][r[i].y]=1;
	}

	while(m--){
		int bot;
		scanf("%d", &bot);
		if (r[bot].d=='F')



	}
}
