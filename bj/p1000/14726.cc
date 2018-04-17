#include <stdio.h>

using namespace std;
int main(){

	int T; scanf("%d", &T);
	while(T--){
		char s[18]; scanf("%s", s);

		int ans=0;
		for (int i=15; i>=0; i--){
			if ( i%2 ==0){
				int tmp = s[i]-'0';

				tmp*=2;
				if (tmp/10) {
					tmp = tmp%10+ tmp/10%10;
				}
				ans+=tmp;
			}
			else  ans += s[i]-'0';
		}

		if ( ans%10 == 0) printf("T\n");
		else printf("F\n");

	}
}
