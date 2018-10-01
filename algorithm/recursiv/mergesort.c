#include <stdio.h>

int a[1000000], b[1000000], c[1000000];

void swap(int *a, int *b){ *a^=*b; *b^=*a; *a^=*b; }
void merge(int l, int m, int r){
	int n1 = m-l+1, n2=r-m;
	for (int i=0; i<n1; i++) b[i]=a[l+i];
	for (int i=0; i<n2; i++) c[i]=a[m+i+1];

	int i=0, j=0, k=l;

	while (i< n1 && j < n2) {
		if (b[i] <= c[j]) { a[k++] = b[i++];}
		else a[k++] = c[j++];
	}
	while (i<n1) a[k++] = b[i++];
	while (j<n2) a[k++] = c[j++];
}

void split(int l, int r){
	if (l<r){
		int m=(l+r)/2;
		split(l,m);
		split(m+1,r);
		merge(l,m,r);
	}
}
int main(){

	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	split(0, n-1);

	for (int i=0; i<n; i++) printf("%d", a[i]);
}
