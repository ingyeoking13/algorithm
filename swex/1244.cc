#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int n, m, mx, a[6], len;
int swap(int &a, int &b) {int tmp=b; b=a, a=tmp;}
int mk(int* a){
	int ret=0;
	for (int i=len-1; i>=0; i--){ ret*=10; ret+=a[i]; }
	return ret;
}

void dfs(int cnt){
//	printf("======%d\n", mk(a));

	if (cnt == m){
		int sum=mk(a);
		mx =max(mx, sum);
		return; 
	}

	int chk=0;

	for (int i=0; i<len; i++){
		for (int j=0; j<len; j++){
			if (i==j) continue;
			int cur = mk(a);
			swap(a[i], a[j]);
			int next = mk(a);
//			printf("mx %d now %d next %d %d\n", mx, cur, next, cnt);

			if (cur<=next){
				chk=1;
				dfs(cnt+1);
			}
			swap(a[i],a[j]);
		}
	}

	/*
	if (!chk) {
		if ( (m-cnt)%2==0) {
			int sum = mk(a);
			mx = max(mx,sum);
			return;
		}
		else {
			int mn=10, mn2=10, mni, mn2i;
			for (int i=0; i< cnt; i++){
				if (mn > a[i]) mn2=mn, mn2i=mni, mn=a[i], mni=i;
				else if ( mn2 >a[i] ) mn2=a[i], mn2i=i;
			}
			swap(a[mn2i], a[mni]);
			int sum= mk(a);
			mx =max(mx, sum);
			swap(a[mn2i], a[mni]);
			return;
		}
	};
	*/

};

int main(){
	int T; scanf("%d", &T);

	for (int t=1; t<=T; t++){
		scanf("%d %d", &n, &m); 
		memset(a, -1, sizeof(a));
		len=0, mx=0;

		for (int i=0; n; i++) {
			a[len++] = n%10; 
			n/=10; 
		}

		dfs(0);
		printf("#%d %d\n", t, mx);
	}
}
