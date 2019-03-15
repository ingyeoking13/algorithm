#include <stdio.h>
int n, a[1000][1000], d[1000][1000][2]; char c[1000][1000][2];
void go(int q, int w, int e){
	if ((q>=0) && (w>=0)) {
		if(c[q][w][e]=='D') go(q-1,w,e);
		else go(q, w-1, e);
	}
  if (c[q][w][e]) printf("%c", c[q][w][e]);
}
int min(int x, int y) { if (x<y) return x; return y;}
int main(){
	int zero=0, chk=0;
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
			if (a[i][j]==0) zero=i*n+j, chk=1;
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (i==0 && j==0);
			else if (i==0)  d[i][j][0]=d[i][j-1][0], d[i][j][1]=d[i][j-1][1], c[i][j][0]='R', c[i][j][1]='R'; 
			else if (j==0)  d[i][j][0]=d[i-1][j][0], d[i][j][1]=d[i-1][j][1], c[i][j][1]='D', c[i][j][0]='D'; 

			else{
				if (d[i][j-1][0]> d[i-1][j][0]) d[i][j][0]=d[i-1][j][0], c[i][j][0]='D';
				else d[i][j][0]=d[i][j-1][0], c[i][j][0]='R'; 
				if (d[i][j-1][1]> d[i-1][j][1]) d[i][j][1]=d[i-1][j][1], c[i][j][1]='D'; 
				else d[i][j][1]=d[i][j-1][1], c[i][j][1]='R';
			}
			int tmp=a[i][j];
			while(tmp%2==0 && tmp)  tmp/=2, d[i][j][0]++; 
			tmp=a[i][j];
			while(tmp%5==0 && tmp)  tmp/=5, d[i][j][1]++; 
		}
	}

	int ans=min(d[n-1][n-1][0],d[n-1][n-1][1]);
	if (chk && ans > 1){
		printf("1\n");
		for (int i=0; i<zero/n; i++) printf("D"); for (int i=0; i<zero%n; i++) printf("R");
		for (int i=0; i<n-zero%n-1; i++) printf("R"); for (int i=0; i<n-zero/n-1; i++) printf("D");
	} else{
		printf("%d\n",ans);
		int k=0; 
		if (d[n-1][n-1][0]>d[n-1][n-1][1]) k=1;
		go(n-1, n-1, k);
		printf("\n");
	} }
