#include <stdio.h>
#include <string>
#include <map>

using namespace std;

char s[102];
map<string, int> m;
int main(){
	int n; scanf("%d", &n);
	scanf("%s", s);
	int cnt=0;
	string ans;

	for (int i=0; i<n-1; i++){
		string tmp;
		tmp.push_back(s[i]);
		tmp.push_back(s[i+1]);
		m[tmp]++;
		if ( m[tmp] > cnt) cnt= m[tmp], ans=tmp;
	}
	printf("%s\n", ans.c_str());

}
