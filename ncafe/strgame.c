#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	int cnt=0, n=0;
	char str[4][6], block[4][6];
	int check[4][6];
	int r, c;
	int w=0, f=0; //승률
	double per=0;

	//initializing
	for(int i=0; i<4; i++) 
		for(int j=0; j<6; j++){
			block[i][j]='X';
			check[i][j]=0;
	}
	srand((unsigned)time(NULL));

	for(int i=0; i<4; i++){
		for(int j=0; j<6; j++){
			str[i][j]=rand()%26+'A';
			cnt=0; n=0; 
			for(int y=0; y<4; y++){
				for(int x=0; x<6; x++){
					if((y!=i || x!=j) && str[y][x]==str[i][j]){
						cnt++; 
						if(cnt>=2) { n=1; j--; break; }
					}
				}
				if(n==1){ break; }
			} 
		}
	}

	for(int i=0; i<4; i++){
		for(int j=0; j<6; j++){
			printf("%5c", str[i][j]);
		}
		printf("\n\n");
	}
	puts("");

	while(1){
		if(w>=12) break;
		r=rand()%3; c=rand()%5;
		if(check[r][c]==0){
		block[r][c]=str[r][c];
		for(int i=0; i<4; i++){
			for(int j=0; j<6; j++){
				printf("%5c", block[i][j]);
			}
			printf("\n\n");
		} 

		printf("    성공 : %d\n", w);
		printf("    실패 : %d\n", f); printf("    > ");

		int x, y;
		scanf("%d %d", &y, &x);
		if((r!=y || c!=x) && str[y][x]==block[r][c]){
			block[y][x]=str[y][x];
			w++;
			check[r][c]=1;
			check[y][x]=1;
		}
		else if((r==y && c==x) || str[y][x]!=block[r][c]){
			f++;
			block[r][c]='X';
			}
		}
	}
	per=(double)w/((double)(w+f))*100.0;
	printf("승률 : %.1lf\n", per);
	return 0;

}
