#include <stdio.h>

int main(){

	int now=0, max=0;
	for (int i=0; i<10; i++){
		int a, b; scanf("%d %d", &a, &b);
		now+=b;
		if (now>10000) now=10000;
		now-=a;
		if (now<0) now=0;
		if (now>max) max=now;
	}
	printf("%d\n", max);

}
