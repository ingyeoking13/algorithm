#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<pair<string, int> > v;
map<string, int> mym;
int p[100001];

int ufind(int now){
	if (now == p[now]) return now;
	else return p[now] = ufind(p[now]);
}

int main(){
	int n, k, m;
	
	scanf("%d %d %d", &n, &k, &m);
	v.resize(n+1);
	for (int i=1; i<=n; i++){
		string s; 
		cin>>s;
		v[i].first = s;
	}

	for (int i=1; i<=n; i++) p[i]=i;
	for (int i=1; i<=n; i++){
		int tmp; scanf("%d", &tmp);
		v[i].second =tmp;
	}
	for (int i=1; i<=n; i++) mym.insert({v[i].first, i});

	for (int i=0; i<k; i++){

		int tmp; scanf("%d", &tmp);
		int mn=1e9+1;
		int one;
		scanf("%d", &one);
		for (int j=1; j<tmp; j++){
			int two; scanf("%d", &two);

			int p1= ufind(one), p2 = ufind(two);
			if (v[p1].second < v[p2].second) p[p2]=p1;
			else p[p1]=p2;
		}
	}

	long long ans=0;
	for (int i=0; i<m; i++){
		string s; cin>>s;
		ans+=(long long)v[ufind(mym.find(s)->second)].second;
	}
	printf("%lld\n", ans);
}
