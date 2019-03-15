#include <bits/stdc++.h>

using namespace std;

stack<int> st;
int a[(int)2e5+1];

int main(){
	int n, k; scanf("%d %d", &n, &k);
	int cur=1;
	st.push(2e5+3); st.push(n+1);

	for (int i=0; i<n; i++){
		if (i<k) scanf("%d", &a[i]);
		else a[i] = st.top() -1;
		st.push(a[i]);
		while(st.top() == cur) st.pop(), cur++;
	}
	if (st.size() > 1) return !printf("-1\n");
	for (int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
