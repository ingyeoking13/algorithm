#include <bits/stdc++.h>

using namespace std;
typedef struct{ int x, y;}pos;
bool operator<(pos a, pos b){
	if ( a.y== b.y ) return a.x > b.x;
	else return a.y >b.y;
}

int main(){
	int n ; scanf("%d", &n);
	priority_queue<pos> pq;
	for (int i=0; i<n; i++) {
		int x, y;
		scanf("%d %d", &x, &y); 
		pq.push({x, y});
	}
	for (int i=0; i<n; i++) {
		pos now= pq.top(); pq.pop();
		printf("%d %d\n", now.x, now.y);
	}
}
