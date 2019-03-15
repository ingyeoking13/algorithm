#include <stdio.h>
#include <math.h>

double maxd( double a, double b) { return a<b?b:a; }

int main(){
	double r, x1, y1; scanf("%lf %lf %lf", &r, &x1, &y1);
	double x2, y2; scanf("%lf %lf", &x2, &y2);

	if ( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)<r*r ){
		double a = (y1-y2)/(x1-x2), b = y1-a*x1;
		if ( x1==x2 && y1 == y2) a=1, b=y1-x1;

		double A = a*a+1;
		double B = 2*a*b - 2*a*y1 - 2*x1;
		double C = x1*x1 + b*b - 2*b*y1 + y1*y1 - r*r;

		double ax = (-B+sqrt(B*B-4*A*C))/(2*A);
		double ay = y1+sqrt(r*r-(ax-x1)*(ax-x1));
		double bx = (-B-sqrt(B*B-4*A*C))/(2*A);
		double by = y1-sqrt(r*r-(ax-x1)*(ax-x1));
		if ( a<0 ) ay=-ay, by=-by;

		double realx, realy;
		if ( maxd((x2-ax)*(x2-ax)+(y2-ay)*(y2-ay), 
							(x2-bx)*(x2-bx)+(y2-by)*(y2-by))
			 	 == (x2-ax)*(x2-ax)+(y2-ay)*(y2-ay)){
			realx  = ax, realy = ay;
		}
		else realx = bx, realy = by;

		double dist = sqrt((x2-realx)*(x2-realx)+(y2-realy)*(y2-realy));
		printf("%lf %lf %lf\n", (x2+realx)/2, (y2+realy)/2, dist/2);
	}
	else printf("%lf %lf %lf\n", x1, y1, r);
} 
