#include <stdio.h>
char a[3][3], b[3][3];
int win(char p[3][3]){
	int ret=0;
	for (int i=0; i<3; i++) {
		int chk=1;
		if (p[i][0]==0) continue;
		for (int j=1; j<3; j++) if(p[i][0]!=p[i][j])  chk=0;
		if (chk) ret=1;
	}

	int ret2=0;
	for (int j=0; j<3; j++){
		int chk=1;
		if (p[0][j]==0) continue;
		for (int i=1; i<3; i++) if(p[0][j]!=p[i][j]) chk=0;
		if (chk) ret2=1;
	}

	int ret3=0, ret4=0;
	if (p[0][0]!=0 && p[0][0] == p[1][1] && p[0][0]==p[2][2]) ret3=1;
	if (p[0][2]!=0 && p[0][2] == p[1][1] && p[0][2]==p[2][0]) ret4=1;
	return ( ret || ret2 || ret3 || ret4);
}

int main(){

	for (int i=0; i<3; i++) scanf("%s", a[i]);

	int p1=0, p2=0;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (a[i][j]=='X') p1++;
			else if (a[i][j]=='0') a[i][j]=0, b[i][j]='0', p2++;
			else a[i][j]=0;
		}
	}

	if (p2>p1 || p1>p2+1) printf("illegal\n");
	else if (win(a) || win(b)){
		if (win(a)){
			if (p1<=p2) printf("illegal\n");
			else printf("the first player won\n");
		}
		else{
			if (p1>p2) printf("illegal\n");
			else printf("the second player won\n");
		}
	}
	else{
		if (p1+p2==9) printf("draw\n");
		else if (p1>p2) printf("second\n");
		else printf("first\n");
	}
}
