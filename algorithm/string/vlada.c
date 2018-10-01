#include <stdio.h>

char arr[][4]={"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(){

	int i, j, match[100];
	char str[101];

	for (i=0; i<100; i++) match[i]=0;
	for (i=0; i<101; i++) str[i]='\0';
	scanf("%s",str);
	for (i=0; str[i]; i++) match[i]=1;
  
	for (i=0;str[i+1];)  
		for (j=0;j<sizeof(arr)/sizeof(arr[0]);j++){
			if(str[i]==arr[j][0] && str[i+1]==arr[j][1] && !arr[j][2])
			{ match[i]=0; i+=2;  break;}
			else if (str[i]==arr[j][0] && str[i+1]==arr[j][1] && str[i+2]==arr[j][2])
			{ match[i]=0; match[i+1]=0; i+=3; break; }
			if (j==sizeof(arr)/sizeof(arr[0])-1) { i++;}
		}

	for (i=0,j=0;i<100;i++) j+=match[i];

	printf("%d\n", j);
	return 0;
}
