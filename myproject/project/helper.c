#include <stdio.h>
#include <string.h>
#include "helper.h"

void clrBuf(){
	while (getchar()!='\n');
}

int getInt(){
	char c='x'; int n;
	while(c!='\n'){
		printf("숫자를 입력해주세요 > ");
		scanf("%d%c", &n, &c);
		if (c!='\n') {
			clrBuf();
			printf("*** ERROR *** 오직 정수만 가능합니다!\n");
		}
	}
	return n;
}

void pause(){
	printf("(아무 키나 눌러주세요....)\n");
	clrBuf();
}

int validInt(int a, int b){
	int n;
	while(1){
		n= getInt();
		if (n>= a && n<=b) break;
		printf("*** ERROR *** %d~ %d 사이의 정수만 가능합니다!\n", a, b);
	}
	return n;
}

void printHead(const char *str){
	for (int i=0; i<3; i++){
		printf("+");
		if (i==1) {
			for (int j=0; j<20; j++)  printf(" "); 
			printf("%s", str);
			for (int j=0; j<30; j++)  printf(" "); 
			int len=strlen(str);
			for (int j=0; j<len; j++) printf("\b");
		}
		else for (int j=0; j<50; j++) printf("-");
		printf("+\n");
	}
}

void menu(){
	printHead("Menu");
	printf("0. 종료\n");
	printf("1. 숫자 개수 세기\n");
	printf("2. 팀 밸런스 맞추기\n");
	printf("3. 스도쿠 풀기!\n");
	printf("4. 베스킨 라빈스 31\n");
	printf("=====================");
}

void mySystem(){

	int n=1;
	while(n){
		menu();
		n=validInt(0, 4);
		if (n==1) printf("NOT AVAILABLE\n");
		else if(n==2) printf("NOT AVAILABLE\n");
		else if(n==3) printf("NOT AVAILABLE\n");
		else if(n==4) printf("NOT AVAILABLE\n");
		if (n) pause();
	}
	printf("시스템 종료....\n");
}

