#include <string>
#include <vector>
#include  <stdio.h>
using namespace std;
class Solution {
public:
    long long p[20000];
    string shiftingLetters(string S, vector<int>& shifts) {
			int sz = shifts.size();
			p[sz-1]= shifts[sz-1]%26;
			for (int i=sz-2; i>=0; i--)
			{
				p[i] = (p[i+1] + shifts[i]%26)%26;
			}

			int len = S.length();
			for (int i=0; i<len; i++)
			{
				S[i] = (S[i]-'a'+p[i])%26;
				S[i] += 'a';
			}
			return S;
    }
};

int main()
{
	Solution s;
	vector<int> shifts;
	shifts.push_back(3);
	shifts.push_back(5);
	shifts.push_back(9);

	string S;
	S="abc";

	printf("%s\n",s.shiftingLetters(S, shifts).c_str());
}
