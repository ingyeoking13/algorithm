#include <stdio.h>

int main(){

	int num, arr[1000];
	scanf("%d", &num);
	for(int i=0; i<num;i++) scanf("%d", &arr[i]);

	for(int i=0; i<num;i++){
		for (int j=num-1; j>i; j--){
			if (arr[j]<arr[j-1]){
				int temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(int i=0; i<num;i++) printf("%d\n", arr[i]);
}
