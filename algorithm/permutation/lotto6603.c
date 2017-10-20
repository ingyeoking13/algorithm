#include <stdio.h>

void swap(int* a, int* b){
	int tmp=*a;
	*a = *b;
	*b = tmp;
}

int perm(int* a, int n){
	int i=n-1;
	while(i>0 && a[i]<=a[i-1]) i--;
	if (i<=0) return 0;
	int j=n-1;
	while(a[i-1]>=a[j]) j--;
	swap(&a[j], &a[i-1]);
	j=n-1;
	while (i<j){
		swap(&a[j],&a[i]);
		i++;
		j--;
	}
	return 1;
}

int main(){

	int num, i, arr[13], parr[13];

	while(1){
		scanf("%d", &num);
		if (!num) break;
		for(i=0;i<num;i++)
			scanf("%d", &arr[i]);
		for(i=0;i<num;i++){
			if(i<6) parr[i]=0;
			else parr[i]=1;
		}

		do{
			for(i=0;i<num;i++)
				if(!parr[i]) printf("%d ", arr[i]);
			printf("\n");
		}while(perm(parr, num));
		printf("\n");
	}

	return 0;

}
