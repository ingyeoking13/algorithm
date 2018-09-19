#include <bits/stdc++.h>

int a[3];
int main(){
	for (int i=0; i<3; i++) scanf("%d", &a[i]);
	std::sort(a, a+3);
	for (int i=0; i<3; i++) printf("%d ", a[i]);
}
