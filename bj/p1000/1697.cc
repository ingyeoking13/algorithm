#include <bits/stdc++.h>

using namespace std;
bool v[100001];
typedef struct{ int now, sec; }pos;

int main(){
	int s, e; scanf("%d %d", &s, &e);
	queue<pos> q;
	
	q.push({s, 0});
	v[s]=1;
	while(!q.empty()){
		pos nPos = q.front(); q.pop();
		int now = nPos.now, sec = nPos.sec;

		if (now == e) return !printf("%d\n", sec);

		if (now+1 <= 100000 && !v[now+1]) q.push({now+1, sec+1}), v[now+1]=1;
		if (now-1 >= 0 && !v[now-1]) q.push({now-1, sec+1}), v[now-1]=1;
		if (now*2 <= 100000 && !v[now*2]) q.push({now*2, sec+1}), v[now*2]=1;
	}
}
