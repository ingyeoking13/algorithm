#include <stdio.h>
#include <algorithm>

using namespace std;

struct Person{ int n; char s[101]; };
Person a[100000];

bool cmp(const Person& a, const Person& b){
	return a.n <b.n;
};

int main(){
	int n; scanf("%d", &n);

	for (int i=0; i<n; i++) scanf("%d %s", &a[i].n, a[i].s);

	stable_sort(a, a+n, cmp);
	for (int i=0; i<n; i++){
		printf("%d %s\n",a[i].n, a[i].s);
	}
}
