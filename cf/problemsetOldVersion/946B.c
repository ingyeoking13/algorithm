#include <stdio.h>

int main(){
	long long a, b; scanf("%lld %lld", &a, &b);
	while(1){

		int chk=0;
		if ( !a || !b ) break;

		if ( a>= 2*b ) a%=(2*b), chk=1;
		if ( !chk && b>= 2*a ) b%= (2*a), chk=1;

		if ( !chk)  break;
	}
	printf("%lld %lld\n", a, b);
}
