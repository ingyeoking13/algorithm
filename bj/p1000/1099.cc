#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

vector<string> words;
//vector<vector<bool> > used(50, vector<bool>(50));
string str;
int d[50];

int go(int cur)
{
  if ( cur == str.size() ) return 0;
  if ( d[cur] >= 0) return d[cur];
  d[cur] = 1e2;

  for (int i=0; i<words.size(); i++)
  {
    if ( cur + words[i].size() > str.size() ) continue;

    int tmp_cost =0;
    int len = words[i].size();

    vector<int> cnt1(26);
    vector<int> cnt2(26);
    for (int j=0; j<len; j++)
    {
      if ( str[cur+j] != words[i][j] ) tmp_cost++;
      cnt1[str[cur+j]-'a'] ++;
      cnt2[words[i][j]-'a'] ++;
    }

    bool chk=false;
    for (int j=0; j<26; j++)
    {
      if (  cnt1[j] != cnt2[j] ) chk=true;
    }
    if (chk ) continue;

    d[cur] = min (  (go(cur+len) + tmp_cost), d[cur]);
  }
  return d[cur];
}


int main()
{
  int n;
  cin >> str >> n;

  memset(d, -1, sizeof(d));

  for (int i=0; i<n; i++)
  {
    string word;
    cin >> word;
    words.push_back(word);
  }

  go(0);
  if ( d[0] >= 1e2 ) cout << -1 << "\n";
  else cout << d[0] <<"\n";
}
