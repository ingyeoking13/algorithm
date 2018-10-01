#include <stdio.h>
#include <stdlib.h>

int compare(const void *first,const void *second){
	return (*(int*)first - *(int*)second);
}

int main(){

	int num, i;
	int arr[1000], time;

	//init
	time =0;
	for(i=0; i<1000; i++) arr[i]=0;

	scanf("%d", &num);
	for(i=0; i<num; i++) scanf("%d", &arr[i]);

	qsort(arr, 1000, sizeof(int), compare);
	for(i=0; i<999; i++) arr[i+1]+=arr[i];
	for(i=0; i<1000; i++) time+=arr[i];

	printf("%d\n", time);
}
