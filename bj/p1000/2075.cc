#include <stdio.h>
#include <queue>

using namespace std;
priority_queue<int> n_pq;
priority_queue<int> pre_pq;

int main(){
	int n; scanf("%d", &n);

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++){
			int tmp; scanf("%d", &tmp);
			n_pq.push(tmp);
		}

		while(pre_pq.size()<n) 
		{
			pre_pq.push(n_pq.top());
			n_pq.pop();
		}
		while(!n_pq.empty()) n_pq.pop();
		while(!pre_pq.empty()) 
		{
			n_pq.push(pre_pq.top());
			pre_pq.pop();
		}
	}
	for (int i=0; i<n-1; i++) n_pq.pop();
	printf("%d\n", n_pq.top());

}
