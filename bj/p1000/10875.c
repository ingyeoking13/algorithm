#include <stdio.h>

typedef struct{
	int ux, uy, vx, vy;
}line;
line l[1000];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

int chk(line a, line b){
	if (b.ux - b.vx){
		if ( (a.uy - b.vy)*(a.vy - b.vy)<=0
				&& 
				 (a.vx - b.ux)*(a.ux - b.vx)<=0
			 ) return 1;
		else return 0;
	}
	else{
		if ( (


	}

}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	int tmp;
	char c[3];
	int nowx=0, nowy=0, dir=0;

	for (int i=0; i<m; i++){
		scanf("%d %s", tmp, c);

		l[i].ux = nowx, l[i].uy = nowy;
		nowx += dx[dir]*tmp, nowy += dy[dir]*tmp;
		l[i].vx = nowx, l[i].vy = nowy;

		if ( c[0] == 'L' ) {
			dir++;
			if (dir>3) dir=0;
		}
		else {
			dir--;
			if (dir<0) dir=3;
		}

		int chk=0; //interrupted
		for (int j=0; j<i-1; j++){
		}
	}
}
