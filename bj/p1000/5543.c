#include <stdio.h>

int main(){
	int min=2000, tmp;
	for (int i=0; i<3; i++){
	 	scanf("%d", &tmp);
		if (min>tmp) min=tmp;
	}
	int min2=2000;
	for (int i=0; i<2; i++){
		scanf("%d", &tmp);
		if (min2>tmp) min2=tmp;
	}
	printf("%d\n", min+min2-50);

}
