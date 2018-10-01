#include <stdio.h>
#include <stdlib.h>

int mycmp(const void *a, const void *b){
	return atoi((char*)a) - atoi((char*)b);
}

int main(){

	int i, j, num;
	char arr[100000][105];

	//init
	for(i=0;i<100000;i++) 
		for(j=0;j<105;j++)
		 	arr[i][j]='\0';

	scanf("%d", &num);

	for(i=0;i<num;i++)
		scanf("%s %s", arr[i], arr[i]+4);

	qsort(arr, num, sizeof(arr[0]), mycmp);

	for(i=0;i<num;i++)
		printf("%s %s\n", arr[i], arr[i]+4);
}
