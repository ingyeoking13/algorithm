#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> v1, v2;

bool findFromV2(string s) {
  for (int i=0; i<v2.size(); i++)
  {
    if (s[0] < v2[i][0]) break;
    if (((int) v2[i].find(s) ) >= 0) 
    {
      return true;
    }
  }
  return false;
}
int main() {
  int T; scanf("%d", &T);
  while(T--)
  {
    int n; scanf("%d", &n);
    char s[21];
    for (int i=0; i<n; i++)
    {
      scanf("%s", s);
      v1.push_back(string(s));
    }

    int m; scanf("%d", &m);
    for (int i=0; i<m; i++) 
    {
      scanf("%s", s);
      v2.push_back(string(s));
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    if (m==0) { printf("1\n"); continue; }

    int ans=0;
    while(v1.size() > 0)
    {
      string s("");
      bool chk=0;

      for (int i=0; i<v1[0].length(); i++)
      {
        s += v1[0][i];
        if (!findFromV2(s))
        {
          ans++; 
          chk=1;
          break;
        }
      }

      if (chk == 0) 
      {
        ans++;
        v1.erase(v1.begin());
        continue;
      }

      for (int i=0; i<v2.size(); i++)
      {
        if (s[0]  > v2[i][0] ) 
        {
          v2.erase(v2.begin()+i); 
          i--;
        }
        else break;
      }

      for (int i=0; i<v1.size(); i++)
      {
        if( ((int)v1[0].find(s)) >=0 ) {
          v1.erase(v1.begin(),1);
        }
        if (s[0]  > v1[i][0] ) 
        {
          v2.erase(v2.begin()+i); 
          i--;
        }
        else break;
      }

      while ( v1.size()>0)
      {
        if( s[0] != v1[0][0]) break;
        if( ((int)v1[0].find(s)) >=0 ) v1.erase(v1.begin());
        else break;
      }

    }
    printf("%d\n",  ans);
  }
}
