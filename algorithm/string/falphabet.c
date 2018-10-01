#include <stdio.h>

int main(){

	char input[101];
	int al[26];
	int i;

	for (i=0;i<26;i++) al[i]=-1;
	for (i=0;i<101;i++) input[i]='\0';

	scanf("%s", input);	

  for (i=100;i>=0;i--){
		al[input[i]-97]=i;
	}	

	for (i=0; i<26;i++) printf("%d ", al[i]);
	printf("\n");
}
