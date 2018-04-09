#include <stdio.h>
#include <algorithm>

using namespace std;
int a[100000];
bool cmp(int a, int b) { return a>b; }
int main(){
	int T; scanf("%d", &T); 
	for (int t=1; t<=T; t++){
		int n; scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%d", &a[i]);

		sort(a, a+n, cmp);
		int ans=0;
		for (int i=0; i<n; i++) if (i%3 !=2) ans+=a[i];
		printf("#%d %d\n", t,ans);
	}

}
