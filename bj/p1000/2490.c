#include <stdio.h>

int main(){
	for (int i=0; i<3; i++){
		int s=0;
		for (int j=0; j<4; j++){
			int tmp;
			scanf("%d", &tmp);
			s+=tmp;
		}
		if (s==1) printf("C\n");
		else if (s==2) printf("B\n");
		else if (s==3) printf("A\n");
		else if (s==4) printf("E\n");
		else printf("D\n");
	}
}
