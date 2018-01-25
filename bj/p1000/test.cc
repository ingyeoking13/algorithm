#include <bits/stdc++.h>

using namespace std;
vector<int> a;
int main(){

	for (int i=0; i<100; i++) a.push_back(i);
	for (int i=0; i<a.size(); i++) printf("%d ", a[i]);
	printf("\n");
	printf("\n");

	a.clear();

	for (int i=0; i<a.size(); i++) printf("%d ", a[i]);
	printf("\n");

}
