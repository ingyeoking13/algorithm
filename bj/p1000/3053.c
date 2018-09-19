#include <stdio.h>
#define PI 3.1415926535897932384626433832795

int main(){
	int r; scanf("%d", &r);
	double area = (double)r*r*PI;
	printf("%.06lf\n%.06lf\n", area, (double)r*r*2);
}
