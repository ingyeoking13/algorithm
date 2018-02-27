#include <stdio.h>
#include <string.h>
int main(){
	int n; scanf("%d", &n);
	char older[16], younger[16];
	int old=0, young=1<<30;
	while(n--){
		char tmp[16]; int m, d, y;
		scanf("%s %d %d %d", tmp, &d, &m, &y);

		if ( old < d+m*31+y*31*12 ) {
			old = d+m*31+y*31*12;
			strcpy(older, tmp);
		}
		if ( young > d+m*31+y*31*12){
		 	young = d+m*31+y*31*12;
			strcpy(younger, tmp);
		}
	}
	printf("%s\n%s\n",older, younger);

}
