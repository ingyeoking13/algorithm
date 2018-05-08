#include <stdio.h>

int mx[100001];
int main(){
	for (int i=1; i<=100000; i++){
		for (int j=1; j<i; j++){
			if ( (double)j/i*1000%10 >= 5){
				mx[i]=j;
				break;
			}
		}
	}

	int T; scanf("%d", &T);
	while(T--){









	}



}
