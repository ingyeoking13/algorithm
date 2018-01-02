#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "helper.h"

void countNum(){
	printfHead("CountNum from pic"); 
	int a[1<<25], max=-1;
	for (int i=0; i<(1<<25); i++) a[i]=0;

	FILE *fp= fopen("input.txt", "r");
	if (!fp){
		printf("*** ALERT *** 파일이 존재하지않습니다.\n");
		return ;
	}
	char str[20];

	while(~fscanf(fp, "%s", str)){
		int num=atoi(str);
		a[num]++;
		if (max <num) max=num;
	}

	printf("====================");
	for (int i=0; i<=max; i++) {
		if (a[i]) 
			printf("%d : %d", i, a[i]);
	}

	fclose(fp);
}

void balancing(){


}
