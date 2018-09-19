#include <stdio.h>
#include <string.h>

int main(){
	int T; scanf("%d", &T);

	while(T--){
		double ans=0; char a[20]; 
		scanf("%lf", &ans); scanf("%20[^\n]", a);
		int len = strlen(a);

		for (int i=0; i<len; i++){
			if ( a[i] == '@' ) ans*=3;
			else if (a[i] == '%') ans+=5;
			else if (a[i] == '#') ans-=7;
		}

		printf("%.2lf\n", ans);
//		while(getchar()!='\n');
	}

}
