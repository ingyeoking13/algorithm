#include <stdio.h>

int a[10]={7, 6, 10, 9, 15, 3, 2, 4, 1, 5};
int main(){
	for (int i=0; i<9; i++){
		for (int j=9; j>i; j--){
			if (a[j-1]>a[j]){
				int tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
			}
		}
	}

	for (int i=0; i<10; i++) printf("%d ", a[i]);
	printf("\n");
}
