#include <stdio.h>

int a[4]={1,2,3,4};
int next_combi(){
	int i=3;
	while (i>=0 && a[i]==7-4+i) i--;
	if (i<0) return 0;
	a[i]++;
	for (int j=i+1; j<4; j++) a[j]=a[i]+j-i;
	return 1;

}
int main(){

	do {
		for (int j=0; j<4; j++) printf("%d ", a[j]);
		printf("\n");
	}while(next_combi());


}
