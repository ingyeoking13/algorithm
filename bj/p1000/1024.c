#include <stdio.h>

int main(){
	int n, l;
	scanf("%d %d", &n, &l);
	if (l> 100 || n<0) return printf("-1\n");
	else{
		int peg=n/l, i=0;
		while(peg){
			int len=l+i;
			int chk=peg;
			for (int j=peg; j<peg+len; j++) chk+=j;
			i++; peg--;
		}

	}
}
