#include <stdio.h>
#include <stack>

using namespace std;
stack<int> ans;
int a[50];
int chk[1001];
int main(){

	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	for (int i=n-1; i>=0; i--){
		if( !chk[a[i]]){
			chk[a[i]]=1;
			ans.push(a[i]);
		}
	}

	printf("%lu\n", ans.size());
	while(!ans.empty()){
		printf("%d ", ans.top());
		ans.pop();
	}
	printf("\n");
}
