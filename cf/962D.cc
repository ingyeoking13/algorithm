#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

typedef long long lli;

lli a[200000], key[200000], mult[200000];

map<int,int> pre;

int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	
	for(int i=0;i<50;i++) {
		pre.clear();
		for(int j=0;j<n;j++) 
			if(a[j]) {
			lli t=a[j];
			mult[j]=0;
			while(t%2==0) {
				mult[j]++;
				t/=2;
				if(mult[j]>i) break;
			}
			if(mult[j]!=i) continue;
			key[j]=t;
			if(pre.count(key[j])) {
				a[pre[key[j]]]=0;
				a[j]+=a[j];
				pre.erase(key[j]);
			} else pre[key[j]]=j;
		}
	}
	vector<lli> v;
	for(int i=0;i<n;i++) if(a[i])
		v.push_back(a[i]);
	printf("%d\n",(int)v.size());
	for(int i=0;i<v.size();i++)
		printf("%lld ",v[i]);
	puts("");
	return 0;
}
