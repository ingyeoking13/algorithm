#include <stdio.h>
char a[5]; 
int b[5], c[10], con, pair, triple, four;
int col[4], col5, col4, col3, col2;
int main(){
	for (int i=0; i<5; i++){
		scanf(" %c", &a[i]);
		scanf("%d", &b[i]);
		if (a[i]=='R') col[0]++;
		else if (a[i]=='B') col[1]++;
		else if (a[i]=='Y') col[2]++;
		else if (a[i]=='G') col[3]++;
		c[b[i]]++;
	}
	for (int i=1; i<=9;i++){
		if (c[i]==4)  four=i; 
		else if (c[i]==3) triple=i;
		else if (c[i]==2){
			if (pair) pair*=10;
		 	pair+=i;
		}
	}
	for (int i=0;i<4; i++){
		if (col[i]==5) col5=1; 			else if (col[i]==4) col4=1; 
		else if (col[i]==3) col3=1; else if (col[i]==2) col2=1;
	}
	for (int i=1; i<=5; i++){
		if (c[i] && c[i+1] && c[i+2] && c[i+3] && c[i+4]) con=i; 
	}
	int max;
	for (int i=1; i<=9; i++) if(c[i]) max=i;
	if (con && col5) printf("%d\n", 900+con+4); //1
	else if(four) printf("%d\n", 800+four); //2
	else if(triple && pair) printf("%d\n", 700+triple*10+pair); //3
	else if(col5) printf("%d\n", 600+max);
	else if(con) printf("%d\n",500+con+4); //5
	else if(triple){ //6
		int point;
		for (int i=1; i<=9; i++) if(c[i]==3) point=i;
	 	printf("%d\n", 400+point);
	}
	else if(pair>=10) printf("%d\n", 300+pair/10+pair%10*10);
	else if (pair) printf("%d\n", 200+pair);
	else printf("%d\n", 100+max);
}
