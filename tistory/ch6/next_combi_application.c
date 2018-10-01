#include <stdio.h>

int a[3]={0,1,2};
int b[7]={2, 3, 7, 9, 11, 13 ,17};
int next_combi(){
	int i=2;
	while (i>=0 && a[i]==7-3+i) i--;
	if (i<0) return 0;
	a[i]++;
	for (int j=i+1; j<3; j++) a[j]=a[i]+j-i;
	return 1;

}
int main(){

	do {
		for (int j=0; j<3; j++) printf("%d ", b[a[j]]);
		printf("\n");
	}while(next_combi());


}

