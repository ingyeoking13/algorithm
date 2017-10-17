#include <stdio.h>
#define SIZE 5

double avg(double *value, int n) {
	int i; double sum = 0.0;
	for (i = 0; i < n; i++) sum += *(value + i); 
	return sum;
}

int main() {
	double data[SIZE], result, tmp;
	int i=0, j;

	while(i<SIZE){
		double tmp; int chk=1;

		printf("실수 값 입력(0 제외) : ");
		scanf("%lf", &tmp);
		for (j = 0; j < i; j++) 
			if (data[j] == tmp){
				chk=0;
			 	printf("이미 입력된 값!!!\n");
			}

		if (chk) data[i++]=tmp;

	}
	printf("\n-- 입력값 --\n");
	for (i = 0; i < SIZE; i++) printf("%.2lf\n", data[i]);

	result = avg(data, SIZE);
	printf("배열 내 원소의 합계 = %.2lf\n", result);

	getchar();
	return 0;
}
