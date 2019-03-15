#include<stdio.h>
int main(){
	int a,b,c,d,e, ans=0;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	if(e<d){
		e=e^d;
		d=e^d;
		e=e^d;
	}
	if(a<e && a>d) ans++;
	if(b<e*5 && b>d*5) ans++;
	if(c<e*5 && c>d*5) ans++;
	if(ans==3 || ans==0) printf("YES\n"); else printf("NO\n");

	return 0;
}
