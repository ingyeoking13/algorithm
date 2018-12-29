#include <stdio.h>
#include <vector>
using namespace std;

char s[(int)1e5+5];
int d[(int)1e5+5];
int main()
{
  int n;
  scanf("%d", &n);
  scanf("%s", s);

  d[0] = (s[0]=='G'?1:0);

  int now = (s[0]=='G'?1:0);
  vector<pair<int, int > > v;

  if ( now == 0) v.push_back({1, -1});

  for (int i=1; i<n; i++)
  {
    if (s[i] == 'G') now++;
    else
    {
      if (now> 0) 
      {
        v.push_back({now, 1}); 
        v.push_back({1, -1});
        now=0;
      }
      else v[v.size()-1].first++;
    }
  }
  if ( now >0) v.push_back({now, 1});
  
  int mx = 0;
  for (int i=0; i<v.size(); i++)
  {
    if (  v[i].first == 1 && v[i].second == -1 )
    {
      bool chk=0;
      for (int j= i+2; j<v.size(); j++)
      {
        if ( v[j].second == 1 ) chk=1;
      }

      for (int j= i-2; j>=0; j--)
      {
        if ( v[j].second == 1 ) chk=1;
      }

      int tmp=0;
      if ( i-1 >=0 ) tmp += v[i-1].first;
      if ( i+1 <v.size() ) tmp += v[i+1].first;
      tmp += (chk?1:0);
      if ( mx < tmp ) mx = tmp;
    }
    else
    {
      if ( v[i].second == 1)
      {
        bool chk=0;
        for (int j = i-1; j>=0; j--)
        {
          if ( v[j].second == 1) chk=1;
        }
        for (int j = i+1; j<v.size(); j++)
        {
          if ( v[j].second == 1) chk=1;
        }

        int tmp = v[i].first;
        tmp += (chk?1:0);
        if ( mx< tmp ) mx = tmp;
      }
    }
  }
  printf("%d\n", mx);
}
