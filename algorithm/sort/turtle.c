#include <stdio.h>

int main(){

	int arr[5];
	int i, j, tmp;

	for (i=0;i<4;i++) scanf("%d", &arr[i]);

	//버블 정렬
	for (i=0;i<4;i++)
		for (j=0;j<3-i;j++){
			if (arr[j]>arr[j+1])
			{
				tmp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=tmp;
			}
		}

	printf("%d\n", arr[0]*arr[2]);

	return 0;

}
