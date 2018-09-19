#include <stdio.h>

int min(int a, int b) { if (a<b) return a; return b;}
int main(){
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d\n",min( min(x,w-x),min(y,h-y)));
}
