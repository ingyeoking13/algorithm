#include <stdio.h>
#include <math.h>

int main(){

	int d, a, b; scanf("%d %d %d", &d, &a, &b);
	double py = sqrt(a*a+b*b);
	printf("%d %d\n", (int)((d/py)*a), (int)((d/py)*b));
}
