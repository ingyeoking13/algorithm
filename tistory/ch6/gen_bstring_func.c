#include <stdio.h>

int a[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int next_bstring(){
	int i=9;
	while(i>=0 && a[i]==1) a[i--]=0;
	if (i<0) return 0;
	a[i]=1;
	return 1;
}
int main(){

	do{
		for (int i=0; i<10; i++) printf("%d ", a[i]);
		printf("\n");
	}while(next_bstring());

}
