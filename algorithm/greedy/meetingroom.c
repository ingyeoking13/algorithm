#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int compare2(const void *a, const void *b);

int main(){

	int i, j, count;
	char arr[100000][22];
	int peg, tmp, len, Answer=0;

	//init
	for (i=0;i<100000;i++)
		for (j=0;j<22;j++)
			arr[i][j]='\n';
	scanf("%d", &count);
	for (i=0;i<count;i++){
		scanf("%s", arr[i]);
		scanf("%s", arr[i]+11);
	}

	qsort(arr, count, sizeof(arr[0]), compare2);

	for(i=0, tmp=atoi(arr[0]+11), peg=0, len=0;i<count;i++){
		if (tmp==atoi(arr[i]+11)) len++;
		else {
			if (len>1) qsort(arr+peg, len, sizeof(arr[0]), compare);
			peg=i;
			tmp=atoi(arr[i]+11);
			len=1;
		}
	}
	qsort(arr+peg, len, sizeof(arr[0]), compare);


	for(i=0, peg=-1;i<count;i++){
		if (peg<=atoi(arr[i])){
			Answer++;
			peg=atoi(arr[i]+11);
		}
	}

	printf("%d\n", Answer);
}

int compare(const void *a, const void *b){
	return (atoi((char*)a)- atoi((char*)b));
}

int compare2(const void *a, const void *b){
	return (atoi((char*)a+11)- atoi((char*)b+11));
}
