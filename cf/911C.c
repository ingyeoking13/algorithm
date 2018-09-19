#include <stdio.h>

int main(){
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	if ( (a==2 && b ==2 ) || (b==2 && c==2 ) 
			|| (c==2 && a==2 )) printf("YES\n");
	else if ( a==3 && b== 3 && c==3 ) printf("YES\n");
	else if ( a==1 || b==1 || c==1) printf("YES\n");
	else if ( ( a==2 && b==4 && c == 4) ||
						( a==4 && b==2 && c == 4) ||
						( a==4 && b==4 && c == 2) ) printf("YES\n");
	else printf("NO\n");

}
