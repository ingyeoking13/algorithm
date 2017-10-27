#include <stdio.h> 
#define win(c) a[3*i]==c && a[3*i+1]==c && a[3*i+2]==c || a[i]==c && a[i+3] ==c && a[i+6] ==c || a[0]==c && a[4]==c && a[8]==c || a[2]==c && a[4]==c && a[6]==c

char a[9];
int main(){
	int p1=0, p2=0;
	for (int i=0; i<9; i++) {
		scanf(" %c", &a[i]);
		if (a[i]=='X') p1++;
		else if (a[i]=='0')  p2++;
	}

	int A=0, B=0;
	for (int i=0; i<3; i++){
		if (win('X')) A=1;
		if (win('0')) B=1;
	}

	if (A &&  p1!=p2+1 || B && p1!=p2 || p1!=p2 && p1!=p2+1) printf("illegal");
	else if (A) printf("the first player won");
	else if (B) printf("the second player won");
	else if (p1+p2==9) printf("draw"); 
	else if (p1>p2) printf("second"); 
	else printf("first");
}
