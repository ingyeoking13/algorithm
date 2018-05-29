#include <stdlib.h>
#include <string.h>
typedef struct animal{
	char name[20];
	int age;
}ANIMAL;

int main(){
	ANIMAL *two = (ANIMAL *)malloc(sizeof(ANIMAL));

	strcpy((*two).name, "호랑이");
	(*two).age = 30;
}
