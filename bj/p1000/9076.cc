#include <stdio.h>
#include <algorithm>

using namespace std;

int a[5];
int main(){
	int n; scanf("%d", &n);
	while(n--){

		for (int i=0; i<5; i++) scanf("%d", &a[i]);
		sort(a, a+5);
		if ( a[3] - a[1] >=4 ) printf("KIN\n");
		else {
			printf("%d\n", a[1]+a[2]+a[3]);
		}
	}

}
