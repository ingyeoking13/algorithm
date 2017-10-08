#include <stdio.h>

int a[101][101][101], d[101][101][101], q[1030302], h, t, ans, chk=1;
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};

int main(){
int row, col, hei;
scanf("%d %d %d",&col, &row, &hei);
for (int i=0; i<hei; i++){
for (int j=0; j< row; j++){
for (int k=0; k< col; k++){
scanf("%d", &a[i][j][k]);
if (a[i][j][k]==1) q[t++]= i*row*col+j*col+k;
}
}
}

while(h<t) {
int now=q[h++];
int z = now/(row*col), x=now/col%row, y=now%col;

for (int i=0; i<4; i++){
int nx=x+dx[i], ny= y+dy[i];
if (nx>=0 && ny>=0 && nx<row && ny<col){
if (a[z][nx][ny]==0){
a[z][nx][ny]=1;
q[t++]=z*row*col+nx*col+ny;
d[z][nx][ny]=d[z][x][y]+1;
}
}
}

int dz[2]={-1, 1};
for (int i=0; i<2; i++){
int nz=z+dz[i];
if (nz>=0 && nz<hei){ 
if (a[nz][x][y]==0){
a[nz][x][y]=1;
q[t++]=nz*row*col+x*col+y;
d[nz][x][y]=d[z][x][y]+1;
}
}
}
}

for (int i=0; i<hei; i++){
for (int j=0; j<row; j++){
for (int k=0; k<col; k++){
if (d[i][j][k]>ans) ans=d[i][j][k];
if (a[i][j][k]==0) chk=0; 
}
}
}

if (chk) printf("%d\n", ans);
else printf("-1\n");
}
