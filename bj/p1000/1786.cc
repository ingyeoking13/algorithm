#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>

using namespace std;
char s[1000005];
char pattern[1000005];

vector<int> pi;
int main()
{
	fgets(s, 1000005, stdin);
	fgets(pattern, 1000005, stdin);

	int s_len = strlen(s);
	if ( s[s_len-1] == '\n') {
		s[s_len-1]=0; 
		s_len--;
	}

	int p_len = strlen(pattern);
	if ( pattern[p_len-1] == '\n'){
		pattern[p_len-1] = 0;
		p_len--;
	}

	/*
		 build pi (preprocess)
 */
	vector<int> pi(p_len, 0); // resize with p_len, fill 0
	int begin =1, matched=0;

	while(begin+matched < p_len) {
		if( pattern[begin+matched] == pattern[matched] )
		{
			pi[begin+matched] = matched+1;
			matched++;
		}
		else
		{
			if (matched == 0) begin++;
			else
			{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	/*
		 kmp 
	 */
	vector<int> ans;
	begin=0, matched=0;
	while(begin <= s_len - p_len) {
		if( matched <p_len && s[begin+matched] == pattern[matched])
		{
			matched++;
			if( matched==p_len) 
			{
				ans.push_back(begin+1);
			}
		}
		else
		{
			if (matched==0) begin++;
			else
			{
				begin += matched- pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	printf("%lu\n",ans.size()); 
	for ( auto i: ans) printf("%d ", i);
}
