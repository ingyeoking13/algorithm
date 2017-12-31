#include <stdio.h>
#include <math.h>

double a[1001], b[1001]; 
double max(double x, double y) { return x<y?y:x; }

int main(){
	int n, r; scanf("%d %d", &n, &r);
	for (int i=0; i<n; i++) scanf("%lf", &a[i]);

	for (int i=0; i<n; i++){
		double center=r;
		for (int j=0; j<i; j++){
			center = max(center, b[j]+sqrt(4*r*r-(a[i]-a[j])*(a[i]-a[j])));
		}
		b[i]=center;
		printf("%.10lf ", b[i]);
	}
}
