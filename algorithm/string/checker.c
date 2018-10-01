#include <stdio.h>

int main(){

	int i, j, test_case, Answer;
	char ch, tempch;
	int arr[26], flag;

	//init
	Answer=0;

	scanf("%d" , &test_case); 
	while(getchar()!='\n');

	for (i=0; i< test_case; i++){
		//init
		for (j=0;j<26;j++) arr[j]=1;
		tempch='\0';

		while((ch=getchar())!='\n')
			 if(tempch!=ch) { arr[ch-'a']--; tempch=ch;}
		Answer++;

		for (j=0; j<26; j++) if (arr[j]<0) {Answer--;break;}
	}
	
	printf("%d\n", Answer);


}
