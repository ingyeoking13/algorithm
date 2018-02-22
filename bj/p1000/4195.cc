#include <bits/stdc++.h>

using namespace std;
map<string,int> num;
int sz[200001], p[200001];

int ufind(int now){
	if ( now == p[now]) return now;
	else return p[now] = ufind(p[now]);
}

int main(){
	cin.tie(0);
	int T; scanf("%d", &T);
	while(T--){
		num.clear(); memset(sz, 0, sizeof(sz));
		int len=0;
		for (int i=0; i<=200000; i++) p[i]=i;

		int n; scanf("%d", &n);
			for (int i=0; i<n; i++){
			string fir, sec;
			cin >> fir; cin >> sec;
			if (num.find(fir)==num.end()) { num[fir]=len++; sz[num[fir]]=1;}
			if (num.find(sec)==num.end()) { num[sec]=len++; sz[num[sec]]=1;}

			int one = num[fir], two = num[sec];
			if ( ufind(two) != ufind(one)){
				sz[ufind(two)]+=sz[ufind(one)];
				p[ufind(one)]=p[ufind(two)];
				printf("%d\n",sz[ufind(one)]);
			}
			else printf("%d\n", sz[ufind(one)]);
		}
	}
}
