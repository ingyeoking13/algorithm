#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

char s[150002], s2[150002];

queue<int> v[27]; queue<int> v2[27];

vector<pair<int, int> > ans;

int main()
{
  int n;
  scanf("%d",&n);
  scanf("%s%s", s, s2);
  for (int i=0; i<n; i++)
  {
    if (s[i] =='?') v[26].push(i+1);
    else v[s[i]-'a'].push(i+1);

    if ( s2[i] == '?') v2[26].push(i+1);
    else v2[s2[i]-'a'].push(i+1);
  }

  for (int i=0; i<26; i++)
  {
    while (v[i].size() && v2[i].size())
    {
      ans.push_back({v[i].front(), v2[i].front()});
      v[i].pop();
      v2[i].pop();
    }
  }

  for (int i=0; i<26; i++)
  {
    while(1)
    {
      if ( v[26].size() == 0 || v2[i].size()==0) break;
      ans.push_back({v[26].front(), v2[i].front()});
      v[26].pop(); v2[i].pop();
    }
  }
  for (int i=0; i<26; i++)
  {
    while(1)
    {
      if ( v2[26].size() == 0 || v[i].size()==0) break;
      ans.push_back({v[i].front(), v2[26].front()});
      v2[26].pop(); v[i].pop();
    }
  }

  while( v[26].size()  && v2[26].size() )
  {
    ans.push_back( {v[26].front(), v2[26].front()} );
    v[26].pop(); v2[26].pop();
  }

  printf("%d\n", (int)ans.size());
  for (int i=0; i<ans.size(); i++)
  {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }

} 
