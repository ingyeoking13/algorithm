#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
struct suffix
{
  int idx;
  int rank[2];
  suffix() {};
};

bool mycmp( const suffix& a , const suffix& b)
{
  if ( a.rank[0] == b.rank[0] ) return a.rank[1] < b.rank[1];
  return a.rank[0] < b.rank[0];
}

int main()
{
  int tt=0;
  int T;
  cin >> T;
  while (  ++tt <= T)
  {
    int n;
    char str[405];

    cin >> n;
    cin >> str;

    int len = strlen(str);

    suffix suff[400];
    for (int i=0; i<len; i++)
    {
      suff[i].idx = i;
      suff[i].rank[0] = str[i]-'a';
      suff[i].rank[1] = ((i+1<len)?(str[i+1]-'a'):-1);
    }

    sort(suff, suff+len, mycmp);

    int ind[400];

    for (int k=4; k<2*len; k*=2)
    {
      int rank = 0;
      int prev_rank = suff[0].rank[0];
      suff[0].rank[0] = rank;
      ind[suff[0].idx] = 0;

      for (int i=1; i<len; i++)
      {

        if ( suff[i].rank[0] ==prev_rank && 
            suff[i].rank[1] == suff[i-1].rank[1])
        {
          prev_rank = suff[i].rank[0];
          suff[i].rank[0] = rank;
        }
        else 
        {
          prev_rank = suff[i].rank[0];
          suff[i].rank[0] = ++rank;
        }
        ind[suff[i].idx] = rank;
      }

      for (int i=0; i<len; i++)
      {
        int nxt_idx = suff[i].idx + k/2;
        suff[i].rank[1] = (nxt_idx<len)?suff[ind[nxt_idx]].rank[0]:-1;
      }
      sort(suff, suff+len,  mycmp);
    }

    cout << "#" << tt << " " << str + suff[n-1].idx << "\n";
  }
}
