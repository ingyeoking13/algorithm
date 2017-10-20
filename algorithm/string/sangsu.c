#include <stdio.h>

int main(){

	char a[3], b[3], temp;
  int i;

	scanf("%s %s", a, b);

	temp=a[0];
	a[0]=a[2];
	a[2]=temp;

	temp=b[0];
	b[0]=b[2];
	b[2]=temp;

	for (i=0;i<3;i++){
		if(a[i]>b[i]) { printf("%s", a); break; }
		else if (a[i]<b[i]) { printf("%s", b); break; }
	}	
	printf("\n");
	return 0;
}
