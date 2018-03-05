#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	while(n){

		int chk=1;
		int tmp = n;

		while(tmp){

			if ( tmp%10 == 7 || tmp%10 == 4 ) ;
			else { chk=0; break; }

			tmp/=10;
		}

		if ( chk ) return !printf("%d\n", n);

		n--;
	}

}
