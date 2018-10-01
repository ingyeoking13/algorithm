#include <stdio.h>
#include <stdlib.h>
int mycmp(const void* a, const void* b){
	return (*(int *)a - *(int *)b);
}
void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int perm(int *a, int len){
	int i=len-1;
	while(i >0 && a[i] <a[i-1]) i--;
	if (i<=0) return 0;
	int j=len-1;
	while(a[i-1]>a[j]) j--;
	swap(&a[i-1],&a[j]);
	j=len-1;
	while(i<j){
		swap(&a[i],&a[j]);
		i++;
		j--;
	}
	return 1;
}

int main(){

	int i, T, arr[8], tmp, ans=0;
	scanf("%d", &T);

	for (i=0;i<T; i++)
		scanf("%d", &arr[i]);

	qsort(arr, T, sizeof(int), mycmp);

	do{
		tmp=0;
		for (i=0;i<T-1;i++){
			if(arr[i]-arr[i+1]>0) tmp+=arr[i]-arr[i+1];
			else tmp+=arr[i+1]-arr[i];
		}
		if (tmp>ans) ans=tmp;
	}while(perm(arr,T));

	printf("%d\n", ans);
	return 0;
}

