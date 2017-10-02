#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[100], ans[100], ans2[100]="ZZZZZZZZZ";
int a[100], j=0;

int mycmp(const void* a, const void* b){
	return *(int *)a - *(int *)b;	
}

void swap(int *a, int* b){
	int tmp=*b;
	*b=*a;
	*a=tmp;
}

int perm(int n){
	int i=n-1;
	while (i>0 && a[i-1] >= a[i]) i--;
	if (i<=0) return 0;
	int j=n-1;
	while (a[j] < a[i-1]) j--;
	swap(&a[i-1], &a[j]);
	j=n-1;
	while(i<j){
		swap(&a[j],&a[i]);
		i++;
		j--;
	}
	return 1;
}

int main() {

	fgets(str, 100, stdin);
	str[strlen(str)-1]=0;

	for (int i=0; str[i]; i++){
		if (str[i]!=' '){
			if (str[i+1]==' ' || !str[i+1]) a[j++]=str[i]-'0';
			else if ( '0'<=str[i+1] && str[i+1]<='9'){
				a[j++]= (str[i]-'0')*10+str[i+1]-'0';
				i++;
			}
		}
	}

	qsort(a, j, sizeof(int), mycmp);

	do{
		int head=0;
		memset(str, 0, 100);

		for(int i=0; i<j; i++){
			if (a[i]/10) {
				str[head++]=a[i]/10+'0';
				str[head++]=a[i]%10+'0';
			}
			else str[head++]=a[i]+'0';
		}
		if(strcmp(str,ans)>0) strcpy(ans, str);
	}while(perm(j));

	qsort(a, j, sizeof(int), mycmp);

	do{
		int head=0;

		memset(str, 0, 100);
		for(int i=0; i<j; i++){
			if (a[i]/10) {
				str[head++]=a[i]/10+'0';
				str[head++]=a[i]%10+'0';
		}
			else str[head++]=a[i]+'0';
		}

		if(strcmp(str,ans2)<0) strcpy(ans2, str);
	}while(perm(j));

	printf("%d\n", atoi(ans)+atoi(ans2));
	return 0;
}

