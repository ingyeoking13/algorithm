#include <stdio.h>
#include <string.h>

int main(){
	char input[101], tmp[101];
	scanf("%s", input);

	int len=strlen(input); // 문자열의 총길이

	int k=0; // 새로 생성하는 문자열의 길이를 저장할 변수. 
	for(int i=0; i<len; i++) 
		if (i%2) tmp[k++]=input[i]; //홀수 인덱스만을 저장해놓는다.

	tmp[k]=0; // 문자열 끝에 null 문자 추가.

	// tmp[] ="elWrd"

	len= len/2+len%2; // 짝수 인덱스의 길이를 계산

	for (int i=0; i<len; i++)  //짝수 인덱스를땡겨온다.
		input[i]=input[i*2];     // HloolWorld 와 같이 문자열이 바뀐다.

	strcpy(input+len, tmp);   //W <-- 부터 tmp 문자열을 복사하면된다.
	printf("%s\n", input);
}
