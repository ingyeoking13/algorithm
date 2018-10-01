#include <stdio.h>

int main(){

	int i;
	int score, sum=0;

	for (i=0;i<5;i++){
		scanf("%d", &score);
		while(getchar()!='\n');
		if (score<40) sum+=40;
		else sum+=score;
	}

	printf("%d\n", sum/5); 
}
