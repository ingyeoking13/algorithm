#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	freopen("in.in", "w", stdout);
	printf("100 80 20\n"); 


	for (int i=0; i<80; i++){
		int x=rand()%100;
		int y=rand()%100;
		printf("%d %d\n", x, y);
	}

}
