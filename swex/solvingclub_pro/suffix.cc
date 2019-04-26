/*
  baekjoon 13264 접미사배열2
  https://www.acmicpc.net/problem/13264
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s[(int)1e5+3];

typedef struct suffix{ 
  int idx, rank[2]; 
  bool operator < ( struct suffix a) const
  {
    if ( rank[0] == a.rank[0] ) return rank[1] < a.rank[1];
    return rank[0] < a.rank[0];
  }
}suffix;

int main()
{
  scanf("%s", s);
  int n = strlen(s);

  suffix sa[(int)1e5];

  for (int i=0; i<n; i++) 
  {
    sa[i].idx = i;
    sa[i].rank[0] = s[i] - 'a';
    sa[i].rank[1] = (i+1 < n)?s[i+1]-'a':-1;
  }
  sort(sa, sa+n);

  int ind[(int)1e5];
  for (int k=2; k<=n; k*=2 )
  {
    int rank = 0;
    int prev_rank = sa[0].rank[0];
    sa[0].rank[0] = rank;
    ind[sa[0].idx] = 0;

    for (int i=1; i<n; i++)
    {
      if ( sa[i].rank[0] != prev_rank || sa[i].rank[1] != sa[i-1].rank[1])
      {
        rank++;
      }

      prev_rank = sa[i].rank[0];
      sa[i].rank[0] = rank;
      ind[sa[i].idx] = i;
    }

    for (int i=0; i<n; i++)
    {
      int nextidx = sa[i].idx + k;
      sa[i].rank[1] = (nextidx < n )?sa[ind[nextidx]].rank[0]:-1;
    }

    sort(sa, sa+n);
  }

  int ans[(int)1e5];
  for (int i=0; i<n; i++)
  {
    ans[i] = sa[i].idx;
    printf("%d\n", ans[i]);
  }
}
