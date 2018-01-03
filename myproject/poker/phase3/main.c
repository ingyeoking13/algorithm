#include <stdio.h>
#include <stdlib.h>
#include "iohelper.h"
#include "game.h"

void menu();

int main(){
#if defined(_WIN32)
	system("title Texas Holdem Game");
	system("mode con: cols=64 lines=48");
#endif
	int n=1;

	while(n){
		clear();
		menu();
		n=getIntRange(0, 2);
		if (n==1) poker(0);
		else if (n==2) poker(1);
	}
	printf("Thx for enjoy...\n");
	pause();
}

void menu(){
	printLines("** Texas Holdem Menu **");
	
	for (int i=0; i<50; i++) printf(" ");
	printf("\n");

	printf("1. Player vs Computer\n");
	printf("2. Player vs Player\n");
	printf("0. exit\n");

}
