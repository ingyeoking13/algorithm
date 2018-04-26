#include <stdio.h>
#include <string.h>
#include <math.h>

#define MSZ 100
#define CMPSZ 100

typedef struct{ int x, y; }pos; //pos struct  x, y
int edge[MSZ][MSZ][CMPSZ]; // if edge (x, y) bomb can (z)th camp, then  edge[x][y][z]=1;
int chk[CMPSZ];           // chk for camp is in set  <-- is used for set cover
pos camp[10001], p[100];  // camp[i] store ith camp (x, y). p stands for parent. 
                          //it means, p[i] store ith camp's its parent (x, y) <-- where to bomb
int campsz, n, m, r;

int setcover(){

	int ans=0; // answer , min set cover
	while(1){ // iterate until there is no bomb position
		int mx=0; // max checks how many camps can be destroyed by just one bomb
		int mxx=0, mxy=0; // mxx stores mx cnt's x, mxy stores mx cnt's y

		for (int i=0; i<m; i++){
			for (int j=0; j<m; j++){
				
				int cnt=0;
				for (int k=0; k<campsz; k++){
					if(edge[i][j][k]){ // if bomb at (x,y) can destroy k th camp
						if(!chk[k]) cnt++; //and k th camp is not in a set, cnt++
					}
				}
				if ( mx < cnt) { mx= cnt, mxx=i, mxy=j; } // store max

			}
		}

		if (mx==0) break; // if max is 0, then we don't need more bombs

		ans++; // cnt one more bomb

		for (int i=0; i<campsz; i++){
			if (edge[mxx][mxy][i]) {
				p[i].x = mxx, p[i].y = mxy; // we make ith camp's parent (mxx, mxy)
				chk[i]=1; 									// we make ith camp be in a set
			}
		}
	}

	return ans;
}

int main(){
	freopen("in.in", "r", stdin);

	scanf("%d %d %d", &m, &n, &r);
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
					edge[i][j][k]=1; // i, j can destroy -> kth camp
				}
			}

		}
	}

	printf("%d\n", setcover());

	//print
	for (int i=0; i<campsz; i++){
		printf("camp x: %d y: %d ", camp[i].x, camp[i].y);
		printf("bomb x: %d y: %d\n", p[i].x, p[i].y);
	}

	char board[MSZ][MSZ]; memset(board, 0, sizeof(board));
	for (int i=0; i<campsz; i++) board[camp[i].x][camp[i].y]='C';
	for (int i=0; i<campsz; i++) {
		board[p[i].x][p[i].y] = 'B';

		for (int j=0; j<m; j++){
			for (int k=0; k<m; k++){
				int x= j, y = k;
				int dist=(p[i].x-x)*(p[i].x-x)+ (p[i].y-y)*(p[i].y-y);
				if ( dist <= r*r ) {
					if (!board[x][y]) board[x][y]='*';
				}
			}
		}
	}

	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++){
			printf("%c", board[i][j]?board[i][j]:' ');
		}
		printf("\n");
	}

}
