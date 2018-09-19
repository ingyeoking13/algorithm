#include <stdio.h>

int main(){

	int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
	if (d<=c){
		if ( 2*d < c ) printf("-1\n");
		else if ( 2*d >= 2*a) printf("-1\n");
		else if ( 2*d >= 2*b) printf("-1\n");
		else printf("%d\n%d\n%d\n", 2*a, 2*b, c);
	}
	else{
		if ( 2*c < d ) printf("-1\n");
		else if ( 2*d >= 2*a) printf("-1\n");
		else if ( 2*d >= 2*b) printf("-1\n");
		else printf("%d\n%d\n%d\n", 2*a, 2*b, d);
	}
}
