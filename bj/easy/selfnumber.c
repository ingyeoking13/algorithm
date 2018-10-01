#include <stdio.h>
int main(){

	int i;
	int arr[20000];

	for(i=0;i<10000;i++)
		arr[i]=i;

	for(i=0;i<10000;i++){
		if(i<10)
			arr[i+i]=0;
		else if(i<100)
			arr[i+i/10+i%10]=0;
		else if(i<1000)
			arr[i+i/100+(i%100)/10+i%10]=0;
		else
			arr[i+i/1000+(i%1000)/100+(i%100)/10+i%10]=0;
		}

	for(i=0;i<10000;i++)
		if (arr[i]!=0)
			printf("%d\n", arr[i]);

	return 0;
}
