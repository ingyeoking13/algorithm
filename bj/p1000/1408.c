#include <stdio.h>

int main(){
	int a, b, c, d, e, f;
	scanf("%d:%d:%d",&a, &b, &c);
	scanf("%d:%d:%d",&d, &e, &f);

	int h, m, s;
	if ((a>d) ||  (a==d && b>e ) || (a==d && b==e && c>=f)){
		h=24+d-a, m=e-b, s=f-c;
	}
	else{ h=d-a, m=e-b, s=f-c; }
	if (s<0) s+=60, m--;
	if (m<0) m+=60, h--;
	printf(h>9?"%d:":"0%d:",h); 
	printf(m>9?"%d:":"0%d:",m);
	printf(s>9?"%d":"0%d",s);
	printf("\n");
}
