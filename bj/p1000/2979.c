#include <stdio.h>

int s[101];
int main(){
	int A, B, C; scanf("%d %d %d", &A, &B, &C);

	for (int i=0; i<3; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		for (int j=a; j<b; j++) s[j]++;
	}

	int ans=0;
	for (int i=0; i<101; i++){
		if  ( s[i]  == 3) ans+=(C*3);
		else if ( s[i] == 2) ans+=(B*2);
		else if ( s[i] == 1) ans+=A;
	}
	printf("%d\n", ans);

}
