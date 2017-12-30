#include <stdio.h>
#include <string.h>

char tmp[20];
char b[9][9];
int main(){
	for (int i=0, cnt=0; i<9; i++, cnt++){
		fgets(tmp, 20, stdin);
		if (cnt==3|| cnt==7){ i--; continue;}
		int len= strlen(tmp);
		int col=0;
		for (int j=0; j<len; j++){
			if (tmp[j]=='.' || tmp[j]=='x' || tmp[j]=='o' ) 
				b[i][col++]=tmp[j];
		}
	}

	int x, y;
	scanf("%d %d", &x, &y); x--, y--;
	x=x%3*3, y%=3;
	int val=x+y;

	int chk=1;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if(b[val/3*3+i][val%3*3+j]=='.') chk=0;
		}
	}
	if (chk){
		for (int i=0, c=0; i<9; i++, c++){
			if (c==3 || c==6) printf("\n");
			for (int j=0, c2=0; j<9; j++, c2++){
				if(c2==3 || c2==6) printf(" ");
				if(b[i][j]=='x' || b[i][j]=='o')	printf("%c", b[i][j]);
				else printf("!");
			}
			printf("\n");
		}
	}
	else {
		for (int i=0, c=0; i<9; i++, c++){
			if (c==3 || c==6) printf("\n");
			for (int j=0, c2=0; j<9; j++, c2++){
				if (c2==3 || c2==6) printf(" ");
				if (b[i][j]=='x' || b[i][j]=='o') printf("%c", b[i][j]);
				else {
					if ( val/3*3 <= i && i < val/3*3+3 && 
							 val%3*3 <= j && j < val%3*3+3) printf("!");
					else printf(".");
				}
			}
			printf("\n");
		}
	}
}
