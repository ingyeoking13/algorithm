#include <stdio.h>
#include <string.h>
#include <math.h>

#define MSZ 100
#define CMPSZ 100

typedef struct{ int x, y; }pos;
int edge[MSZ][MSZ][CMPSZ];
int chk[CMPSZ];
pos camp[10001], p[100]; 
int campsz, n, m, k;

int dfs(int nowx, int nowy){
	if (nowx == -1 ) return 1;

	for (int i=0; i<campsz; i++){

		if (edge[nowx][nowy][i]){
			if (chk[i])  continue;

			chk[i]=1;
			int px = p[i].x, py= p[i].y;

			if ( dfs(px, py) ){
				p[i].x = nowx;
				p[i].y = nowy;
				return 1;
			}
		}

	}
	return 0;
}

int mxflow(){
	int ans=0;
	for (int i=0; i<campsz; i++) p[i].x=-1, p[i].y=-1;

	for (int i=0; i<m; i++){
		for (int j=0; j<m; j++){
			memset(chk, 0, sizeof(chk));
			if (dfs(i, j)) {
				ans++;
			}
		}
	}

	return ans;
}

int main(){
	freopen("in.in", "r", stdin);

	scanf("%d %d %d", &m, &n, &k);
	double r = 2*sqrt(m);

	campsz=0;

	for (int i=0; i<n; i++){
		int x, y; 
		scanf("%d %d", &x, &y);
		camp[campsz].x =x; camp[campsz].y= y;
		campsz++;
	}

	for (int i=0; i<m; i++){
		for (int j=0; j<m; j++){

			for (int k=0; k<campsz; k++){
				double x= i, y = j;
				double nx = camp[k].x, ny = camp[k].y;

				double dist =(x-nx)*(x-nx)+(y-ny)*(y-ny);
				if (dist <= r*r){
					edge[i][j][k]=1;
//					printf("%d %d %d\n", i, j, k);
				}
			}

		}
	}
	printf("%d\n", mxflow());
	for (int i=0; i<campsz; i++){
		printf("x: %d y: %d\n", p[i].x, p[i].y);
	}

}
