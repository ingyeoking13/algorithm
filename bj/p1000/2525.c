#include <stdio.h>

int main(){
	int h, m; scanf("%d %d", &h, &m);
	int n; scanf("%d", &n);
	while(n--){
		m++;
		if (m==60){
		 	m=0, h++;
			if (h==24) h=0;
		}
	}
	printf("%d %d\n", h, m);
}
