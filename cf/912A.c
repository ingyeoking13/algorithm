#include <stdio.h>

int main(){
	int a, b; scanf("%d %d",  &a, &b);
	int x, y, z; scanf("%d %d %d", &x, &y, &z);
	long long na = (long long)2*x+y, nb = (long long) 3* z+y;
	na=a-na>=0?0:na-a;
	nb=b-nb>=0?0:nb-b;
	printf("%lld\n", na+nb);
}
