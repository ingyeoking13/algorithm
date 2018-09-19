#include <bits/stdc++.h>

using namespace std;
int main(){
	int a[5], mean=0;
	for (int i=0; i<5; i++){
		scanf("%d", &a[i]);
		mean+=a[i];
	}
	sort(a, a+5);
	printf("%d\n%d\n", mean/5, a[2]);
}
