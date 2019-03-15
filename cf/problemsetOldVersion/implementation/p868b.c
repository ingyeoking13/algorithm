#include <stdio.h>

int main(){
	int h, m, s, dep, arr;
	scanf("%d %d %d %d %d", &h, &m, &s, &dep, &arr);

	if(dep>arr){
		arr=arr^dep;
		dep=arr^dep;
		arr=arr^dep;
	}

	int ans=0;
	if (h<arr && h>=dep) ans++;
	if (m<arr*5 && m>=dep*5) ans++;
	if (s<arr*5 && s>=dep*5) ans++;

	if (ans==0 || ans==3) printf("YES\n");
	else printf("NO\n");
}
