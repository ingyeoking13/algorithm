#include <iostream>
#include <string.h>
#include <set>

using namespace std;

char s[(int)1e5+2];
vector<int> latestIdx[3];
vector<int> pos[26];
int inUsed[(int)1e5];
bool good[3];

set<int> duplicate;

int main()
{
  int n, q;
  cin >> n >> q;
  cin >> s; 

  int len = strlen(s);
  for (int i=0; i<len; i++) pos[ s[i] -'a' ].push_back(i);
  for (int i=0; i<3 ; i++ ) good[i] = true;

  while (q-- )
  {
    char op[3]; int u; char al[3];

    cin >> op >> u >> al;

    if (op[0] == '+' )
    {
      int l = 0, r = pos[al[0]-'a'].size()-1;

      int ret = -1;
      while ( l <= r )
      {
        int mid = (l+r)/2;
        if ( mid >= latestIdx[ u ] )
        {
          ret = mid;

          if ( inUsed[ ret ] ) l = mid+1;
          else r = mid-1;
        }
        else l = mid+1;
      }

      if ( ret == -1 )
      {
        good[u] =false;
        latestIdx[
      }
      else 
      {
        if ( inUsed[ ret ] ) good[u] =false;
        duplicate.insert(ret);
        inUsed[ ret ]++; 
        latestIdx[ u ] .push_back( ret );
      }
    }
    else
    {

      inUsed[latestIdx[u].back()]--;
      if ( inUsed[latestIdx[u].back()] == 1) 
      {

      }
      latestIdx[u].pop_back();

    }


  }



}
