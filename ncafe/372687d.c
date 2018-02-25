// if problem has dynamic size. 
// make sure that perm should be less than billion size...
// it could be terrible calculate size. -ZFC
#include <stdio.h>

int a[26];


int swp(int *x, int *y){ *x^=*y, *y^=*x, *x^=*y; }

int perm(int n){

	int i=n-1;
	while (i >0 && a[i-1] > a[i] ) i--;
	if (i==0) return 0;
	int j=n-1;
	while (a[i-1] > a[j]) j--;
	swp(&a[i-1], &a[j]);

	j=n-1;
	while(i < j){
		swp(&a[i],&a[j]);
		i++;
		j--;
	}
	return 1;
}

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) a[i]=i;

	do{
		for (int i=0; i<n; i++){
			printf("%c", a[i]+'a');
		}
		printf("\n");
	}while(perm(n));

}
