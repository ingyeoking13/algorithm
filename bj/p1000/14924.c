#include <stdio.h>

int main(){
	int s, t, d; scanf("%d %d %d", &s, &t, &d);

	int now=0;
	while(d){
		d-=2*s;
		now++;
	}
	printf("%d\n", now*t);
}
