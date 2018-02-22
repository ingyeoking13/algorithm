#include <cstdio>

int a[19][19], v[19][19][8], v2[19][19][8];
int dx[8] = {-1, -1, 1, 1, 0, -1, 1, 0};
int dy[8] = {0, 1, 0, -1, -1, -1, 1, 1};
typedef struct{ int x, y; }pos;

int chk(int x, int y, int man, int len, int d){
	int ret=1;
	v[x][y][d]=1;
	if ( 0<=x+dx[d] && x+dx[d]< 19 && 
			 0<=y+dy[d] && y+dy[d]< 19){
		if ( a[x+dx[d]][y+dy[d]] == man && !v[x+dx[d]][y+dy[d]][d]){
			ret+=chk( x+dx[d], y+dy[d], man, len+1, d);
		}
	}
	if ( 0<=x-dx[d] && x-dx[d]< 19 && 
			 0<=y-dy[d] && y-dy[d]< 19){
		if ( a[x-dx[d]][y-dy[d]] == man && !v[x-dx[d]][y-dy[d]][d]){
			ret+=chk( x+dx[d], y+dy[d], man, len+1, d);
		}
	}
	return ret;
}

pos min(pos a, pos b){
	if ( a.y > b.y ) return b;
	else if ( a.y < b.y ) return a;
	else if (a.x > b.x) return b;
	else return a;
}

pos find(int x, int y, int man, int d){
	pos ret={x, y};
	v2[x][y][d]=1;
	if ( 0<=x+dx[d] && x+dx[d]< 19 && 
			 0<=y+dy[d] && y+dy[d]< 19){
		if ( a[x+dx[d]][y+dy[d]] == man && !v2[x+dx[d]][y+dy[d]][d]){
			ret=min(ret, find( x+dx[d], y+dy[d], man, d));
		}
	}
	if ( 0<=x-dx[d] && x-dx[d]< 19 && 
			 0<=y-dy[d] && y-dy[d]< 19){
		if ( a[x-dx[d]][y-dy[d]] == man && !v2[x-dx[d]][y-dy[d]][d]){
			ret=min(ret,find( x+dx[d], y+dy[d], man, d));
		}
	}
	return ret;
}

int main(){

	for (int i=0; i<19; i++){
		for (int j=0; j<19; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for (int i=0; i<19; i++){
		for (int j=0; j<19; j++){
			for (int k=0; k<8; k++){
				if (a[i][j] && !v[i][j][k]){
					if(chk(i, j, a[i][j], 1, k)==5){
						pos mpos = find(i, j, a[i][j], k);
						return !printf("%d\n%d %d\n", a[i][j],  mpos.x+1, mpos.y+1);
					}
				}
			}
		}
	}
	printf("0\n");
}
