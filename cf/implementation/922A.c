#include <stdio.h>

int main(){
	int c, o; scanf("%d %d", &c, &o);
	int nowo = o, nowc = o-1;

	if ( nowc == 0 && c>0 ) printf("No\n");
	else if ( nowc >0 && ((c-nowc)%2 == 1)) printf("No\n");
	else if ( c-nowc <0) printf("No\n");
	else if ( o == 0 ) printf("No\n");
	else printf("Yes\n");
}
