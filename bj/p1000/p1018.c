#include <stdio.h>

char b[51][51];
char w[8][8], nw[8][8];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=0; i<n;i++){
		for (int j=0; j<m; j++){
			scanf(" %c", &b[i][j]);
		}
	}

	for (int i=0; i<8;i++){
		for (int j=0; j<8; j++){
			if((i+j)%2==0) w[i][j]='W';
			if((i+j)%2) w[i][j]='B';
		}
	}

	for (int i=0; i<8;i++){
		for (int j=0; j<8; j++){
			if((i+j)%2==0) nw[i][j]='B';
			if((i+j)%2) nw[i][j]='W';
		}
	}

	int tmp1=0, tmp2=0;
	int ans1=1<<10, ans2=1<<10;
	for (int i=0; i<=n-8;i++){
		for (int j=0; j<=m-8; j++){
			for(int k=i; k<i+8; k++){
				for (int l=j; l<j+8; l++){
					if(b[k][l]!=w[k-i][l-j]) tmp1++; 
					if(b[k][l]!=nw[k-i][l-j]) tmp2++;
				}
			}
			if (ans1>tmp1) ans1=tmp1;
			if (ans2>tmp2) ans2=tmp2;
			tmp1=0; tmp2=0;
		}
	}
	printf("%d\n", ans1>ans2?ans2:ans1);

}
