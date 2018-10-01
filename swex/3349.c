#include <stdio.h>

typedef struct {int x, y; }node;
node pos[1000];

int abs( int x ) { return x<0?-x:x; }
int min( int x, int y) { return x<y?x:y; }

int main(){
	int T; scanf("%d", &T);
	for (int t=1; t<=T; t++){
		int w, h, n; scanf("%d %d %d", &w, &h, &n);
		for (int i=0; i<n; i++) {
			scanf("%d %d", &pos[i].x, &pos[i].y);
		}
		node now = pos[0];

		int ans=0;
		for (int i=1; i<n; i++){
			if ( now.x < pos[i].x && now.y < pos[i].y){
				ans+=min(abs(now.x-pos[i].x),abs(now.y-pos[i].y));
				ans+=abs(abs(now.x-pos[i].x)-abs(now.y-pos[i].y));
			}
			else if (now.x > pos[i].x && now.y > pos[i].y){
				ans+=min(abs(now.x-pos[i].x),abs(now.y-pos[i].y));
				ans+=abs(abs(now.x-pos[i].x)-abs(now.y-pos[i].y));
			}
			else {
				ans+=abs(abs(now.x-pos[i].x)+abs(now.y-pos[i].y));
			}
			now=pos[i];
		}
		printf("#%d %d\n", t, ans);
	}

}
