#include <bits/stdc++.h>

using namespace std;
int main(){
	int T=1;

	char str[2001];
	stack<char> s;
	while(1){
		memset(str,0, sizeof(str));
		while (!s.empty()) s.pop();

		scanf("%s", str);
		if (str[0] == '-') break;
		int len = strlen(str);

		for (int i=0; i<len; i++){
			if ( str[i] == '{' ) {
				s.push('{');
			}
			else {
				if ((!s.empty()) && s.top() == '{' ) s.pop();
				else s.push('}');
			}
		}

		int sz= s.size();
		int open=0, close=0;
		for (int i=0; i<sz; i++) {
			if (s.top()== '{') open++;
			else close++;
			s.pop();
		}

		int ans=0;
		if (open%2){
			ans += open/2;
			ans += close/2;
			ans += 2;
		}
		else {
			ans += open/2;
			ans += close/2;
		}

		printf("%d. %d\n", T, ans);
		T++;
	}
}
