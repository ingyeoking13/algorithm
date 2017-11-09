#include <stdio.h>
typedef struct{
	char name[20];
	int id, k, e, m;
}student;
student a[4];
int main(){
	for (int i=0; i<4; i++){
		printf("-----%d 번 째 학생-----\n", i+1);
		printf("name : "); scanf("%s", a[i].name);
		printf("ID : "); scanf("%d", &a[i].id);
		printf("korean : "); scanf("%d", &a[i].k);
		printf("english : "); scanf("%d", &a[i].e);
		printf("math : "); scanf("%d", &a[i].m);
		printf("----------------------\n\n");
	}
	for (int i=0; i<4; i++){
		printf("%s ", a[i].name); printf("%d ", a[i].id);
		printf("%d ", a[i].k); printf("%d ", a[i].e);
		printf("%d ", a[i].m); printf("%d \n", (a[i].k+a[i].e+a[i].m)/3);
	}
}
