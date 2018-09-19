#include <stdio.h>
#include <string.h>

char str[7]; int num;
int main(){
	scanf("%s", str);
	int len=strlen(str);
	for (int i=0; i<len; i++){
		num*=16;
		if (str[i]>='0' && str[i]<='9') num+=str[i]-'0';
		else num+=str[i]-'A'+10;
	}
	printf("%d\n", num);
}
