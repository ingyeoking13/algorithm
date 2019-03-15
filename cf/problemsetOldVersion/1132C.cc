#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Seg
{
  int l, r, len;
  Seg(int l, int r) : l(l), r(r), len(r-l+1) {};
  bool operator< (Seg b ) { return len < b.len; };
};

vector<Seg> v;
int main()
{
  int n, q;
  scanf("%d%d", &n, &q);

  for (int i=0; i<q; i++)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    v.push_back(Seg(l, r));
  }

  sort(v.begin(), v.end());
  q= q-2;

  int ans=0;
  while(q--)
  {
    Seg cur = v.back();
    v.pop_back();
    if ( cur.len == 0) break;
    ans += cur.len;

    for (int i=0; i<v.size(); i++)
    {
      if ( cur.l > v[i].r || v[i].l > cur.r) continue;

      int newl = v[i].l;
      if (v[i].l >= cur.l) newl = min(cur.r+1, v[i].r+1); 
      if (v[i].r <= cur.r) v[i].r = max(cur.l-1, v[i].l);
      v[i].l = newl;
      if ( v[i].l > v[i].r ) 
      {
        v[i].len = 0;
        v[i].l = -1, v[i].r= -1;
      }
      else 
      {
        v[i].len = v[i].r- v[i].l+1;
      }
    }
    sort(v.begin(), v.end());
  }

  printf("%d\n", ans);
}
