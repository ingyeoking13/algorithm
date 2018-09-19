#include <stdio.h>
char c[105]; 
int main(){
	int n; scanf("%d", &n);
	scanf(" %s", c); 

	int l=0, r=0, d=0, u=0;
	for (int i=0; i<n; i++) {
			if (c[i]=='U')  u++; 
			else if (c[i]=='D') d++;
			else if (c[i]=='L') l++;
			else if (c[i]=='R') r++;
	}
	int ans=0; ans+=l>r?r:l; ans*=2;
	int ans2=0; ans2+=d>u?u:d; ans2*=2;
	printf("%d\n", ans+ans2);
}
