#include <stdio.h>

int s[2]={0, 0};
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		int x, y, a=0;
		scanf("%d %d", &x, &y);
		if (x<0) a=1;
		s[a]++;
	}
	if (s[0] <= 1 || s[1] <= 1 ) {
		if (s[0]==0 && s[1]==1) printf("NO\n");
		else if (s[0]==1 && s[1]==0) printf("NO\n");
		else if (s[0]==0 && s[1]==0) printf("NO\n");
		else printf("YES\n");
	}
	else printf("NO\n");
}
