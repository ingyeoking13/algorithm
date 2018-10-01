#include <stdio.h>
#include <string.h>

int main(){

	char tmp[101];
	scanf("%101[^\n]", tmp); //엔터(return)키 들어오기 전까지 계속 입력받기

	int len = strlen(tmp);
	int chk = 0;

	for (int i=0; i<len; i++) {  //입력받은 문자열의 길이 까지~
		if (tmp[i]=='@' && (!chk)) //지금 문자의 인덱스가 @이고 한번도 안바꿨을 경우
			tmp[i]='&', chk=1;  
		else if (tmp[i]!='@') 		//지금 문자가 @가 아닌경우 
			chk=0;
	}

	printf("%s\n", tmp);
}
