#include <stdio.h>
#include <algorithm>

using namespace std;
char s[200002];
int main(){
	int n, a, b; 
	scanf("%d %d %d", &n, &a, &b);
	scanf("%s", s);

	int ans=0, st=a>=b;
	for (int i=0; i<n; i++){
		if (s[i] =='*') {
			st=a>=b;
			continue;
		}

		if (st==1){
			if(a)	a-=1, ans++;
			st=0;
		}
		else{
			if(b) b-=1, ans++; 
			st=1;
		}
	}
	printf("%d\n", ans);
}
