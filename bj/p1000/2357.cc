#include <stdio.h>
#include <vector>

using namespace std;

class SegTree{
public:
	int n;
	vector<int> rangeMin, rangeMax;
	SegTree(const vector<int>& a) : n(a.size()-1){
		rangeMin.resize(n*4, 1<<30);
		rangeMax.resize(n*4, -1<<30);
		initMin(a, 1, n, 1);
		initMax(a, 1, n, 1);
	}

	int initMin(const vector<int>&a, int l, int r, int now){
		if ( l ==r) return rangeMin[now] = a[l];
		
		int m = (l+r)/2;
		int lmean = initMin(a, l, m, now*2);
		int rmean = initMin(a, m+1, r, now*2+1);
		rangeMin[now] = min(lmean, rmean);
		return rangeMin[now];
	}

	int initMax(const vector<int>&a, int l, int r, int now){
		if ( l == r) return rangeMax[now] = a[l];

		int m = (l+r)/2;
		int lmax = initMax(a, l, m, now*2);
		int rmax = initMax(a, m+1, r, now*2+1);
		return rangeMax[now] = max(lmax, rmax);
	}

	int queryMin(int l, int r, int now, int nowl, int nowr){
		if ( r < nowl || l > nowr ) return 1<<30; 
		if ( l <= nowl && nowr<=r) return rangeMin[now];

		int m = (nowl+nowr)/2;
		int ret= min(queryMin(l, r, now*2, nowl, m),
							 queryMin(l, r, now*2+1, m+1, nowr));
		return ret;
	}

	int queryMax(int l, int r, int now, int nowl, int nowr){
		if ( r < nowl || l > nowr )  return -1<<30;
		if ( l <= nowl && nowr<= r) return rangeMax[now];

		int m = (nowl+nowr)/2;
		return max(queryMax(l, r, now*2, nowl, m),
							 queryMax(l, r, now*2+1, m+1, nowr));
	}
};

int main(){
	int n, m; scanf("%d %d", &n, &m);

	vector<int> a(n+1);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);

	SegTree S(a);
	while(m--){
		int f, t;
		scanf("%d %d", &f, &t);
		printf("%d %d\n", S.queryMin(f, t, 1, 1, n),
			 								S.queryMax(f, t, 1, 1, n));
	}
}
