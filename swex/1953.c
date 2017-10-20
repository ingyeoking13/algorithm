#include <stdio.h>
#include <string.h>

int plumb[8][4]={ //four direction ^ > v <
	{0, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 1, 0}, {0, 1, 0, 1},
 	{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {1, 0, 0, 1} };

int a[51][51], q[2500], d[51][51];
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1}; //four direction ^ > v <
int main(){
	int T; scanf("%d", &T);

	for (int test_case=1; test_case<=T; test_case++){
		memset(d, 0, sizeof(d));

		int row, col, sx, sy, obj;
		scanf("%d %d %d %d %d", &row, &col, &sx, &sy, &obj);
		for (int i=0; i<row; i++){
			for (int j=0; j<col; j++){
				scanf("%d", &a[i][j]);
			}
		}
		int h=0, t=0;
		q[t++]= sx*col+sy;
		d[sx][sy]=1;
		while(h<t){
			int now=q[h++];
			int x=now/col, y=now%col;
			for (int i=0; i<4; i++){
				int nx=x+dx[i], ny=y+dy[i];
				if(nx>=0 && ny>=0 && nx<row && ny<col){
					if(plumb[a[x][y]][i] ==1 && plumb[a[nx][ny]][(i+2)%4]==1){
						if(!d[nx][ny]) {
							q[t++]=nx*col+ny; 
							d[nx][ny]=d[x][y]+1;
						}
					}
				}
			}
		}

		int ans=0;
		for(int i=0; i<row; i++){
			for (int j=0; j<col; j++){
				if (d[i][j]!=0 && d[i][j]<=obj) ans++;
			}
		}
		printf("#%d %d\n", test_case, ans);
	}
}
