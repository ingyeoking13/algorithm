#include <stdio.h>

#define INT 1
#define FLOAT 0

typedef union iof{
	float b; int a;
}iof;

typedef struct aaa{
	int i_f;
	iof result;
}aaa;

int main(){
	aaa x[2]={
		{ FLOAT, 3.21 },
		{ INT, 4}
	};

	for (int i=0; i<2; i++){
		if (x[i].i_f) printf("%d\n", x[i].result.a);
		else printf("%f\n", x[i].result.b);

	}

}
