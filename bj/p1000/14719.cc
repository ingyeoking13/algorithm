#include <stdio.h>
#include <algorithm>

using namespace std;

int a[500];
int main(){

	int h, w; scanf("%d %d", &h, &w);
	for (int i=0; i<w; i++) scanf("%d", &a[i]);

	int ans=0;
	for (int i=0; i<w; i++){
		int lmx=0, rmx=0;
		for (int j=i-1; j>=0; j--) lmx = max(lmx, a[j]);
		for (int j=i+1; j<w ; j++) rmx = max(rmx, a[j]);

		if ( min(lmx, rmx) - a[i] <=0 ) continue;
		ans += (min(lmx, rmx) - a[i]);
	}
	printf("%d\n" ,ans);

}
