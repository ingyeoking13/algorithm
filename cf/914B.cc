#include <stdio.h>
#include <algorithm>

int a[100002], d[100002];
using namespace std;
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	sort (a, a+n);
	d[n]=0;
	int chk=0, st;
	for (int i=n-1; i>=0; i=st-1){
		int j=i-1;
		while (j>=0 && a[j]==a[i]) j--;

		st = j+1;
		for (j=i; j>=st; j--){
			if (chk) 	d[j]=1;
			else 			d[j]=!d[j+1];
		}
		if (!d[st+1]) chk=1;
	}

	if (d[0]) printf("Conan\n");
	else printf("Agasa\n");
}
