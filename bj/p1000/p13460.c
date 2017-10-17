#include <stdio.h>
char s[11][11]; 
int chk[101][101];
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
typedef struct{
	int R, B;
}node;
node q[10000];

int main(){

	int row, col, hole, h=0, t=1;
	scanf("%d %d", &row, &col);

	for (int i=0; i<row; i++){
	 	scanf("%s", s[i]); 
		for (int j=0; j<col; j++){
			if (s[i][j]=='O') hole=i*col+j;
			else if (s[i][j]=='R') {q[0].R=i*col+j; s[i][j]='.';}
			else if (s[i][j]=='B') {q[0].B=i*col+j; s[i][j]='.';}
		}
	}
	chk[q[0].R][q[0].B]=1;

	while (h<t){
		int red=q[h].R, blue=q[h++].B;

		for (int i=0; i<4; i++){
			int nredx=red/col, nredy=red%col;
			int nbluex=blue/col, nbluey=blue%col;
			while (s[nredx+dx[i]][nredy+dy[i]] != '#' && s[nredx][nredy]!='O'){
				nredx+=dx[i]; nredy+=dy[i];
			}
			while (s[nbluex+dx[i]][nbluey+dy[i]] != '#' && s[nbluex][nbluey]!='O'){
				nbluex+=dx[i]; nbluey+=dy[i];
			}
			int nred=nredx*col+nredy, nblue=nbluex*col+nbluey;
			if((nbluex == nredx) && (nbluey == nredy)){
				if ((hole==nblue) && (hole==nred)) continue;
				if (i==0){
					if (red/col>blue/col) nbluex--;
					else nredx--;
				}
				else if (i==1){
					if (red/col>blue/col) nredx++;
					else nbluex++;
				}
				else if (i==2){
					if (red%col>blue%col) nbluey--;
					else nredy--;
				}
				else{
					if (red%col>blue%col) nredy++;
					else nbluey++;
				}
			}
			nred=nredx*col+nredy, nblue=nbluex*col+nbluey;

			if (chk[nred][nblue]==0) {
//				printf("%d %d\n", nred, nblue);
				chk[nred][nblue]=chk[red][blue]+1;
				if ((hole != nblue) && (hole!=nred)){
/*
		for (int i=0; i<row; i++){
			for (int j=0; j<col; j++){
				if (i*col+j == nblue) printf("B");
				else if (i*col+j == nred) printf("R");
				else printf("%c", s[i][j]);
			}
			if (i==row-1) printf("\t\t %d \n", h-1);
			else printf("\n");
		}
*/
					q[t].R=nred; q[t++].B=nblue;
				}
			}
		}
	}

	int ans=12;
	for (int i=0; i<101; i++)
		if (chk[hole][i]<ans && chk[hole][i]!=0) ans=chk[hole][i];

	if (ans>11) printf("-1\n");
	else printf("%d\n", ans-1);
}
