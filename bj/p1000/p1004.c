#include <stdio.h>

int main(){
	
	int T;
	scanf("%d\n", &T);
	while(T--){
		int sx, sy, dx, dy, n, ans=0;
		scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			int P1 = (sx-x)*(sx-x)+(sy-y)*(sy-y)<r*r;
			int P2 = (dx-x)*(dx-x)+(dy-y)*(dy-y)<r*r;
			if (P1^P2) ans++;
		}
		printf("%d\n", ans);
	}
}
