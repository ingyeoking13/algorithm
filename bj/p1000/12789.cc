#include <bits/stdc++.h>

using namespace std;
int a[1001];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d",&a[i]);

	int i=0, now=1;
	stack<int> s;

	while( i<n ){
		if ( a[i] != now ){
		 	s.push(a[i]);
			i++;
		}
		else i++, now++;

		while ( (!s.empty()) && s.top()  == now) {
			s.pop();
			now++;
		}
	}

	if (s.empty()) printf("Nice\n");
	else 						printf("Sad\n");
}
