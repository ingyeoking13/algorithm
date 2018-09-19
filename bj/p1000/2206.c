#include <stdio.h>
typedef struct{ int now, magic; }pos;
int n, m, sx, sy, ex, ey, a[1001][1001], d[1001][1001][2];
pos q[100000]; int h, t;
int dx[4] ={-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int min(int x, int y) { if (x<y) return x; return y;}
int main(){
scanf("%d %d ", &n, &m);

for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
scanf("%1d", &a[i][j]);

for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
for (int k=0; k<=1; k++) d[i][j][k]=1<<20;

q[t].now=sx*(m+1)+sy; q[t].magic=(a[sx][sy] || a[ex][ey])?0:1;
d[sx][sy][q[t].magic]=1;
t++;

while (h<t){
int now = q[h].now, magic = q[h].magic;  h++;
int x = now/m, y = now%m;

for (int i=0; i<4; i++){
int nx=x+dx[i], ny= y+dy[i];
if (nx>=0 && ny>=0 && nx<n && ny<m){

if (!a[nx][ny]) {
if (d[nx][ny][magic] > d[x][y][magic]+1){
q[t].now=nx*m+ny, q[t].magic=magic, t++;
d[nx][ny][magic]=d[x][y][magic]+1;
}
}
else if (magic && d[nx][ny][0]>d[x][y][magic]+1){
q[t].now=nx*m+ny; q[t].magic=0; t++;
d[nx][ny][magic-1]=d[x][y][magic]+1;
}
}
}
}

if (d[n-1][m-1][1]!=(1<<20) || d[n-1][m-1][0]!=(1<<20)) {
printf("%d\n", min(d[n-1][m-1][1],d[n-1][m-1][0]));
}
else printf("-1");
}

