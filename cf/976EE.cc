#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
struct Pet{ 
	long long hp, dam; 
};
bool cmp(const Pet& a, const Pet& b){
	return a.hp > b.hp;
}

int main(){
	int n, a, b; scanf("%d %d %d", &n, &a, &b);
	vector<Pet> p(n);
	for (int i=0; i<n; i++) scanf("%lld %lld",&p[i].hp, &p[i].dam);

	sort(p.begin(), p.end(), cmp);
	for (int i=0; i<n; i++) printf("%lld %lld\n", p[i].hp, p[i].dam);

	for (int i=0; i<a; i++) p[0].hp*=2;

	long long ans=0;
	for (int i=0; i<b; i++) ans += p[i].hp;
	for (int i=b; i<n; i++) ans += p[i].dam;
	printf("%lld\n", ans);

}

