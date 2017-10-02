#include <stdio.h>
#include <string.h>
 
char a[55];
int d[55];
int main(){

	fgets(a, 55, stdin);
	a[strlen(a)-1]=0;

	for (int i=0; i<strlen(a); i++){
		d[i]=1;
		for (int j=0; j<i; j++){
			if(a[j]<a[i]) d[i]=d[i]>d[j]+1?d[i]:d[j]+1;
		}
	}
	int ans=0;
	for (int i=0; i<55; i++) ans=ans>d[i]?ans:d[i];

	printf("%d\n", 26-ans);
}
