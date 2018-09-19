#include <bits/stdc++.h>
#include <unordered_set>
#define TEN 100000

using namespace std;

unordered_set<long long> s;
queue<long long> q;

int main(){
	int a, b; scanf("%d %d", &a, &b);
	q.push(a*1e5+b);
	while(!q.empty()){
		long long now=q.front(); q.pop();
		long long a= now/TEN;
		long long b= now%TEN;
		printf("%lld %lld\n", a, b);

		for (auto it=s.begin(); it!=s.end(); it++){
			long long before=*it;
			long long ba = before/TEN;
			long long bb = before%TEN;
			if ( b == ba && s.find(a*TEN+bb)==s.end()){
					s.insert(a*TEN+bb);
					q.push(a*TEN+bb);
			}
		}

		if ( a+1<=TEN && b+1<=TEN){
			if (s.find((a+1)*TEN+b+1) == s.end()){
				s.insert((a+1)*TEN+b+1);
				q.push((a+1)*TEN+b+1);
			}
		}
		if ( a%2==0 && b%2 ==0){
			if ( s.find((a/2)*TEN+b/2) == s.end()){
				s.insert((a/2)*TEN+b/2);
				q.push((a/2)*TEN+b/2);
			}
		}
	}
	for (int i=0; i<5; i++){
		scanf("%d %d", &a, &b);
		if(s.find(a*TEN+b) != s.end()) printf("Y\n");
		else printf("N\n");
	}
}
