#include <stdio.h>

int cup[4]={1, 0, 0, 2};
void swap(int* a, int* b) { *a^=*b, *b^=*a, *a^=*b;}
int main(){
	char ch;
	while(ch=getchar()){
		if (ch=='A') swap(&cup[0],&cup[1]);
		else if (ch=='B') swap(&cup[0],&cup[2]);
		else if (ch=='C') swap(&cup[0],&cup[3]);
		else if (ch=='D') swap(&cup[1],&cup[2]);
		else if (ch=='E') swap(&cup[1],&cup[3]);
		else if (ch=='F') swap(&cup[2],&cup[3]);
		else break;
	}
	int s, b;
	for (int i=0; i<4; i++) {
		if (cup[i]==1) s=i;
		if (cup[i]==2) b=i;
	}
	printf("%d\n%d\n", s+1, b+1);
}
