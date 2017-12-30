#include <stdio.h>

int act[100000];
int main(){
	int h1, a1, c1, h2, a2;
	scanf("%d %d %d %d %d", &h1, &a1, &c1, &h2, &a2);

	int turn=0;
	while(h2>0){
		if ( h1>a2 || h2<=a1 ) act[turn++]=1, h2-=a1;
		else h1+=c1,turn++;
		h1-=a2;
	}

	printf("%d\n", turn);
	for (int i=0; i<turn; i++){
		if (act[i]) printf("STRIKE\n");
		else printf("HEAL\n");
	}
}
