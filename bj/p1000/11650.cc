#include <bits/stdc++.h>

using namespace std;
typedef struct{ int x, y;  } pos;
pos a[100001];

int mycmp(pos q, pos w){
	if ( q.x == w.x) return q.y < w.y;
	return q.x < w.x;
}

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d %d", &a[i].x, &a[i].y);
	}

	sort(a, a+n, mycmp);

	for (int i=0; i<n; i++){
		printf("%d %d\n", a[i].x, a[i].y);
	}
}
