#include <bits/stdc++.h>

using namespace std;
typedef struct{ int i, start, left; } person;
int ans[1000];
vector<person> v;
queue<person> q;
bool mycmp(person a, person b){ 
	if (a.start == b.start) return a.i < b.i;
	return a.start < b.start; 
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		memset(ans, 0, sizeof(ans));
		v.clear();

		int n; scanf("%d", &n);

		for (int i=0; i<n; i++) {
			int s, l;
			scanf("%d %d", &s, &l);
			v.push_back({i,s, l});
		}

		sort(v.begin(), v.end(), mycmp);

		int time=1, i=0;
		while(time<=5000){
			while(i < n && v[i].start == time) {
				q.push(v[i]); 
				i++;
			}

			if (!q.empty()) {
				person now = q.front(); q.pop();
				while(now.left<time && !q.empty()){ now=q.front(); q.pop(); }

				if ( now.left>=time) ans[now.i]= time;
			}
			time++;
		}
		for (int i=0; i<n; i++) printf("%d ", ans[i]);
		printf("\n");
	}
}
