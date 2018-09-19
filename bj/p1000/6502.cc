#include <stdio.h>

int main(){

	int cnt=1;
	while(1){
		int r; scanf("%d", &r);
		if (!r) break;
	 	int w, l; scanf("%d %d", &w, &l);
		if ( 2*r*2*r >= w*w+l*l){
			printf("Pizza %d fits on the table.\n", cnt);
		}
		else printf("Pizza %d does not fit on the table.\n", cnt);
		cnt++;
	}
}
