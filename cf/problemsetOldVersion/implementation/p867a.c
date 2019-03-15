#include <stdio.h>

int main(){
	int n, ans=0;
	scanf("%d", &n);
	getchar();
	char str[101];
	scanf("%s", str);
	int now= str[0]=='S'?1:0;
	for (int i=1; i<n; i++){
		if (now){
			if(str[i]=='F'){
				now=0;
				ans++;
			}
		}
		else{
			if(str[i]=='S'){
				now=1;
				ans--;
			}
		}
	}

	printf(ans>0?"YES\n":"NO\n");
}
