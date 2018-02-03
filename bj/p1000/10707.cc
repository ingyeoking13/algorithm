#include <cstdio>

int main(){
	int x; scanf("%d", &x);
	int y, maxy, dy; scanf("%d %d %d", &y, &maxy, &dy);
	int my; scanf("%d", &my);

	int ans = y+ ((my-maxy)*dy>0?(my-maxy)*dy:0);
	if ( ans> my*x) ans=my*x;
	printf("%d\n", ans);
}
