#include <stdio.h>
int a[9]={1, 2, 3, 4, 5, 6, 7, 8, 9}, b[9]={0, 1, 2, 3, 4, 5, 6, 7, 8}, c[9];
int r;

void swap(int* n, int* m){ *n^=*m; *m^=*n; *n^=*m; }
int perm(){
	int i=r-1;
	while (i>0 && c[i]<c[i-1]) i--;
	if (i==0) return 0;
	int j=r-1;
	while (c[j]<c[i-1]) j--;
	swap(&c[j], &c[i-1]);
	j=r-1;
	while(i<j){ swap(&c[j],&c[i]); i++; j--; }
	return 1;
}

int comb(){
	int i=r-1;
	while (i>=0 &&  b[i]==9-r+i) i--;
	if (i<0) return 0;
	b[i]++;
	for (int j=i+1; j<r; j++) b[j]=b[i]+j-i;
	return 1;
}

int main(){

	printf("Please input size \"r\"");
	scanf("%d", &r);

	do{
		for(int i=0; i<r; i++) c[i]=a[b[i]];
		do{
			for(int i=0; i<r; i++) printf("%d ", c[i]); 
			printf("\n");
		}while(perm());
	}while(comb());

	return 0;
}

