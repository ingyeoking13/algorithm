#include <stdio.h>

int a[5]={3, 2, 4, 1, 5};
int main(){
	for (int i=0; i<4; i++){
		for (int j=0; j<4-i; j++){
			if (a[j]>a[j+1]){
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}

	for (int i=0; i<5; i++) printf("%d ", a[i]);
	printf("\n");
}
