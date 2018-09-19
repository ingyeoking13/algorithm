#include <stdio.h>
#include <stdlib.h>

int a[9]={1,1};
int in[9], ans[9];

int perm(){
	int i=8;
	while (i>0 && a[i]>=a[i-1]) i--;
	if (i==0) return 0;
	int j=8;
	while (a[j]>=a[i-1]) j--;

	int tmp=a[j];
	a[j]=a[i-1];
	a[i-1]=tmp;

	j=8;
	while(i<j){
		tmp=a[j];
		a[j]=a[i];
		a[i]=tmp;
		i++;
		j--;
	}
	return 1;
}

int mycmp(const void* a, const void* b){
	return *(int *)a - *(int *)b;
}

int main(){

	for (int i=0; i<9; i++) scanf("%d", &in[i]); 

	do{
		int sum=0;
		for (int i=0; i<9; i++) sum+=(!a[i])*in[i]; 

		if (sum==100){
		 for (int i=0; i<9; i++){
			 ans[i]=(!a[i])*in[i];
		 }	 
		}
	}while(perm());
	qsort(ans, 9, sizeof(int), mycmp);
	for (int i=2; i<9; i++) printf("%d\n", ans[i]);
}
