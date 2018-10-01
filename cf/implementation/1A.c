#include <stdio.h>

int main(){

	int n, m, a; scanf("%d %d %d", &n, &m, &a);
	int row = n/a+(n%a!=0);
	int col = m/a+(m%a!=0);
	printf("%I64d\n",(long long)row*col );
}
