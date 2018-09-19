#include <stdio.h>

int main(){

	int n; scanf("%d", &n);
	int an=0, l;
	for (int i=1;; i++){
		an+=i;
		if (n<=an) { l=i; break; }
	}
	if (!(l%2)) printf("%d/%d\n",l-(an-n), 1+(an-n));
	else printf("%d/%d\n",1+(an-n), l-(an-n));
}
