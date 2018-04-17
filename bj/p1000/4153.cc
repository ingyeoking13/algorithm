#include <stdio.h>

using namespace std;
int main(){

	while(1){
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		a*=a, b*=b, c*=c;
		if ( a== 0 && b==0 && c==0) break;

		if ( a == b+c || b == a+c || c == a+b ) printf("right\n");
		else printf("wrong\n");
	}

}
