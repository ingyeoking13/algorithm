#include <stdio.h>

int main(){

	int n, i, x=0, y=0, tmp;
	printf("X의 원소개수 입력 : ");
	scanf("%d", &n);
	for (i=0; i<n; i++){
		printf("\t집합 x의 %d 번째 원소 입력 : ", i+1);
		scanf("%d", &tmp);
		x=x|(1<<tmp-1);
	}

	printf("Y의 원소개수 입력 : ");
	scanf("%d", &n);
	for (i=0; i<n; i++){
		printf("\t집합 x의 %d 번째 원소 입력 : ", i+1);
		scanf("%d", &tmp);
		y=y|(1<<tmp-1);
	}

	//int 범위는 양으로 최대 2^31 
	//정도이며 2^30 까지 안전하게 표현가능
	//unsigned 와 long long 해주면 더 가능하지만 제한여전히존재
	printf("집합 X = <");
	for(i=0;i<31; i++) {
		if (x>>i&1) printf(" %d", i+1);
	}
	printf(">\n");


	printf("집합 Y = <");
	for(i=0;i<31; i++) {
		if (y>>i&1) printf(" %d", i+1);
	}
	printf(">\n");


	printf("합집합 = <");
	tmp=x|y;
	for(i=0;i<31;i++) 
		if (tmp>>i&1) printf(" %d", i+1);
	printf(">\n");
	
	printf("교집합 = <");
	tmp=x&y;
	for(i=0;i<31;i++) 
		if (tmp>>i&1) printf(" %d", i+1);
	printf(">\n");

	printf("차집합(X-Y) = <");
	tmp=x&~y;
	for(i=0;i<31;i++) 
		if (tmp>>i&1) printf(" %d", i+1);
	printf(">\n");

	printf("차집합(X-Y) = <");
	tmp=y&~x;
	for(i=0;i<31;i++) 
		if (tmp>>i&1) printf(" %d", i+1);
	printf(">\n");

	printf("대칭차집합 = <");
	tmp=x^y;
	for(i=0;i<31;i++) 
		if (tmp>>i&1) printf(" %d", i+1);
	printf(">\n");

	return 0;

}
