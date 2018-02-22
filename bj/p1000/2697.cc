#include <bits/stdc++.h>

char seq[81];

void swap(char* x, char* y){ char tmp= *x; *x=*y, *y=tmp;}

int perm(int size){
	int i=size-1;
	while(i>0 && seq[i-1] >= seq[i]) i--;
	if (i==0) return 0;
	int j=size-1;
	while(j>0 && seq[j] <= seq[i-1]) j--;
	swap(&seq[j], &seq[i-1]); 
	j=size-1;
	while(i<j){
		swap(&seq[i], &seq[j]);
		i++, j--;
	}
	return 1;
}

int main(){
	int n; scanf("%d", &n);
	while(n--){ 
		scanf("%s", seq);
		if (perm(strlen(seq))){
			printf("%s\n", seq);
		}
		else printf("BIGGEST\n");
	}
}
