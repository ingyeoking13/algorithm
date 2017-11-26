#include <stdio.h>

int a[6]={0,0,0,1,1,1};
int swp(int x, int y) { a[x]^=a[y], a[y]^=a[x], a[x]^=a[y]; } 
int perm(){
	int i=5;
	while (i>0 && a[i-1]>=a[i]) i--;
	if (i==0) return 0;
	int j=5;
	while (a[j]<=a[i-1]) j--;
	swp(j, i-1);
	j=5;
	while(i<j){
		swp(i,j);
		i++, j--;
	}
	return 1;
}
int main(){

	int s[6], total=0, chk=0;
	for (int i=0; i<6; i++) scanf("%d", &s[i]), total+=s[i];

	do{
		int tmp=0; 
		for (int i=0; i<6; i++){
			if (a[i])  tmp+=s[i];
		}
		if (tmp*2==total)  chk=1;
	}while(perm());

	printf(chk?"YES\n":"NO\n");

}
