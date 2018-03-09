#include <stdio.h>

int main(){

	int n, m, k; scanf("%d %d %d", &n, &m, &k);

	int ans=0;
	for (int i=0; i<k; i++){
		int x, y; scanf("%d %d", &x, &y);
		if ( x%2 && y%2 ) ans |=1;
		else if ( (x+1)%2 && y%2 ) ans |=2;
		else if ( x%2 && (y+1)%2) ans |=4;
		else if ( (x+1)%2 && (y+1)%2) ans |=8;
	}

	printf(ans==15?"YES\n":"NO\n");
}
