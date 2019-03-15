#include <bits/stdc++.h>

using namespace std;
int a[2001], v[2001], ans;
int dx[2] ={-1 ,1};
typedef struct{ int i, len, now, chg;}point;
queue<point> q;

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<n; i++){
		memset(v, 0, sizeof(0));
		q.push({i, 1, a[i], 0});
		v[i]=1;
		while(!q.empty()){
			point now = q.front(); q.pop();
			if ( ans< now.len) ans=now.len;
			for (int i=0; i<2; i++){
				int next= now.i+dx[i];
				if ( 0<=next && next<n){
					if ( !v[next]){
						if ( now.now != a[next]){
							if ( now.chg < 3) {
								q.push({next, now.len+1, a[next], now.chg+1});
								v[next]=1;
							}
						}
						else {
							q.push({next, now.len+1, now.now, now.chg});
							v[next]=1;
						}
					}
				}
			}
		}
	}

	printf("%d\n", ans);
}
