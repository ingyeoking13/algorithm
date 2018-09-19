#include <bits/stdc++.h>

using namespace std;
int a[21];
int main(){
	for (int i=1; i<=20; i++) a[i]=i;
	stack<int> s;

	for (int i=0; i<10; i++){
		int f,t ; scanf("%d %d", &f, &t);
		for (int j=f; j<=t; j++){
			s.push(a[j]);
		}
		for (int j=f; j<=t; j++){
			a[j]=s.top(); s.pop();
		}
	}

	for (int i=1; i<=20; i++) printf("%d ", a[i]);
	printf("\n");
}
