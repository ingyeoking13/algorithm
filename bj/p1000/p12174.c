#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);

	for (int test=1 ; test<=T; test++){
		int t;
		scanf("%d", &t);
		getchar();
		printf("Case #%d: ", test);
		while (t--){
			char c; int num=0;
			for (int i=0; i<8; i++ ){
				c=getchar();
				num*=2;
				if (c=='I') num++;
			}
			printf("%c", num);
		}
		printf("\n");
	}
}
