#include <stdio.h>

int x[100000], y[100000];
int size;

int sigma(int* a){
	int sum=0;
	for (int i=0; i<size;i++)
		sum+=a[i];

	return sum;
}

int main(){

	printf("please input size\n");
	scanf("%d", &size);
	printf("please input x, y\n");
	for (int i=0; i< size; i++){
		scanf("%d", &x[i]);
		scanf("%d", &y[i]);
	}

	int sx=sigma(x);
	int sy=sigma(y);

	int sq_x[100000];
	for(int i=0; i< size; i++) 
		sq_x[i]=x[i]*x[i];

	int mul_xy[100000];
	for(int i=0; i< size; i++)
		mul_xy[i]=x[i]*y[i];

	int ssq_x=sigma(sq_x);
	int smul_xy=sigma(mul_xy);

	double det = (ssq_x * size) - (sx*sx);

	if (det){
		double a= ((size)*smul_xy +(-sx)*sy)/det;
		double b= ((-sx)*smul_xy + ssq_x *sy)/det;

		printf("a= %lf\n", a);
		printf("b= %lf\n", b);
		return 0;
	}
}
