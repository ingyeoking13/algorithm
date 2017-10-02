#include <stdio.h>

int main(){

	char arr[15];
	int i, time;

	//init
	for(i=0;i<15;i++) arr[i]='\0';
	scanf("%s", arr);
	time=0;
	
	for(i=0;arr[i];i++) {
		if (arr[i]<=67)
			time+=3;
		else if (arr[i]<=70)
			time+=4;
		else if (arr[i]<=73)
			time+=5;
		else if (arr[i]<=76)
			time+=6;
		else if (arr[i]<=79)
			time+=7;
		else if (arr[i]<=83)
			time+=8;
		else if (arr[i]<=86)
			time+=9;
		else 
			time+=10;
	}	

	printf("%d\n", time);
	return 0;
}
