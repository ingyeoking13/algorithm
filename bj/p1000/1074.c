#include <stdio.h>

int x, y, cnt, ans;
int go(int n, int r, int c){
	if (n==1){
		cnt++;
		if ( x==r && y== c) return cnt;
		cnt++;
		if ( x==r && y== c+1) return cnt;
		cnt++;
		if ( x==r+1 && y == c) return cnt;
		cnt++;
		if (x==r+1 && y == c+1) return cnt;
		return 0;
	}
	else {
		int ret=0;
		if(ret=go (n/2, r, c)) return ret;
		else if(ret=go (n/2, r, c+n)) return ret;
		else if(ret=go (n/2, r+n, c)) return ret;
		else if(ret=go (n/2, r+n, c+n)) return ret;
		return ret;
	}
}

int main(){
	int n;
	scanf("%d %d %d", &n, &x, &y);
	printf("%d\n",go(1<<n, 0, 0)-1);
}
