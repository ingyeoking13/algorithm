#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(0));
	int a=rand()%6, b = rand()%6, c =pow(a,b);
	printf("%d %d %d\n", a, b,c );
}
