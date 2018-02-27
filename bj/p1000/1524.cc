#include <stdio.h>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int> >pq;
priority_queue<int, vector<int>, greater<int> >pq2;

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n, m; scanf("%d %d", &n, &m);

		for (int i=0; i<n; i++) {
			int tmp; scanf("%d", &tmp);
			pq.push(tmp);
		}

		for (int i=0; i<m; i++) {
			int tmp; scanf("%d", &tmp);
			pq2.push(tmp);
		}

		while(!pq.empty() && !pq2.empty()){
			if ( pq.top() >= pq2.top() ) pq2.pop();
			else pq.pop();
		}
		if ( pq.empty()) printf("B\n");
		else printf("S\n");
		while(!pq.empty()) pq.pop();
		while(!pq2.empty()) pq2.pop();

	}

}
