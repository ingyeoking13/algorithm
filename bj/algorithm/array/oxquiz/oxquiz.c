#include <stdio.h>

int main(){
  
	int T, Case;
	int i, j, score;
	char ox[81];

  scanf("%d", &Case);
	while(getchar()!='\n');

	for (T=0; T<Case;T++){

		//initializing
		score=0;
		j=0;
		for (i=0; i<81; i++) ox[i]='N'; 

		scanf("%s", ox); 
		for (i=0; ox[i]!='N'; i++){
			if(ox[i]=='O') j++;

			else{
				for (;j>0;j--) score+=j;
			}
		}	

		printf("%d\n", score);
	}
	return 0;
}
