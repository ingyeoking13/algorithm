#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;
deque<int> dq;

int main(){
	int n, m, total=0; scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++) dq.push_back(i);

	while(m--){
		int tmp;

		int idx=0;
		scanf("%d", &tmp);

		for (auto i : dq){
			if (i == tmp) break;
			idx++;
		};

		if ( dq.size()/2 < idx ){
			while( dq.front() !=tmp ){
				int k = dq.back();
				dq.pop_back();
				dq.push_front(k);
				total++;
			}
		}
		else{
			while ( dq.front() !=tmp){
				int k = dq.front();
				dq.pop_front();
				dq.push_back(k);
				total++;
			}
		}
		dq.pop_front();
	}
	printf("%d\n", total);
}
