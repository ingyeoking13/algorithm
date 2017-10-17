#include <stdio.h>

int a[5];

int main(){
	int max=-1<<20, min=1<<20;
	printf("-------------------------------\n");
	printf("please input five numbers from 1~9\n");
	for (int i=0; i<5; i++) {
		printf("[%d num?] ", i+1);
		scanf("%d", &a[i]);
		if (a[i]>max) max=a[i]; if (a[i]<min) min=a[i];
	}

	printf("-------------------------------\n");
	printf("array : [");
	for (int i=0; i<5; i++) {
		printf(i<4?"%d, ":"%d ]\n", a[i]);
	}

	while(1){
		printf("\n1. maxval && minval\n2. average\n3. even num counting\n4. exit\n");
		printf("-------------------------------\n");

		int input;
		scanf("%d", &input);
		if (input==1) printf("[maxval] %d\n[minval] %d\n", max, min);
		else if (input==2) {
			double avg=0;
			for (int i=0; i<5; i++) avg+=a[i];
			printf("[avgerage val] %lf\n", avg/5);
		}
		else if (input==3) {
			int cnt=0;
			for (int i=0; i<5; i++) if (a[i]%2==0) cnt++;
			printf("[even num counting] %d\n", cnt);
		}
		else if (input==4) break;
	}
	return 0;
}

