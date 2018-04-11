#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;
char s[101];
int main(){

	for (int t=1; t<=10; t++){

		int n; scanf("%d", &n); 
		scanf("%s", s);
		stack<char> st;

		for (int i=n-1; i>=0; i--) {
			if ( !st.empty()){
				char tmp = st.top();
				if(tmp==s[i]) st.pop();
				else st.push(s[i]);
			}
			else st.push(s[i]);
		}
		int len=0;
		while(!st.empty()){
			char tmp =  st.top();
			st.pop();
			s[len++]=tmp;
		}
		s[len]=0;
		printf("#%d %s\n", t,s);
	}
}
