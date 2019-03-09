#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
using namespace std;

bool dp[(int)1e3][(int)1e3];
int main()
{
  int T;
  cin >> T;

  for (int test_case = 1; test_case<=T; test_case++)
  {
    string s;
    cin >> s;
    memset(dp, 0, sizeof(dp));

    for (int i=0; i<s.size(); i++) dp[i][i] = true;

    int ans =1;

    for (int i=0; i<s.size()-1; i++)
    {
      if ( s[i] == s[i+1] )
      {
        dp[i][i+1] = true;
        ans = 2;
      }
    }

    for (int i=3; i<=s.size(); i++)
    {
      for (int j=0; j<s.size(); j++)
      {
        int start = j, end = j+i-1;

        if (end >= s.size() ) continue;
        if (dp[start+1][end-1] && s[start] == s[end] ) 
        {
          dp[start][end] = true;
          ans = max(ans, i);
        }
      }
    }

    cout << "#" << test_case << " " <<  ans << "\n";
  }
}


