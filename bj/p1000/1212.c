#include <stdio.h>
#include <string.h>

int main(){
	char h[333335];
	scanf("%s", h);

	int i=0, len=strlen(h);
	while(i<len){
		if(h[i]=='0') printf(i?"000":"0"); 
		else if(h[i]=='1') printf(i?"001":"1"); 
		else if(h[i]=='2') printf(i?"010":"10"); 
		else if(h[i]=='3') printf(i?"011":"11"); 
		else if(h[i]=='4') printf("100"); 
		else if(h[i]=='5') printf("101"); 
		else if(h[i]=='6') printf("110"); 
		else if(h[i]=='7') printf("111"); 
		i++; 
	}
	printf("\n");
}
