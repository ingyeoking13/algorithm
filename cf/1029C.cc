#include <stdio.h>
#include <algorithm>
using namespace std;

struct seg
{
  int l, r;
  seg(int l, int r) : l(l), r(r) {}
  seg() : l(0), r(0){}
};

bool mycmp( seg a, seg b)
{
  if (a.l!= b.l) return a.l< b.l;
  else if( a.l==b.l)  return a.r <= b.r;
}

int cnt[(int)3e5];
int main()
{
  int n;
  scanf("%d", &n);
  seg a[(int)3e5];

  for (int i=0; i<n; i++)
  {
    scanf("%d %d", &a[i].l, &a[i].r);
  }
  printf("\n");

  sort(a, a+n, mycmp);

  int l =0, r=0;
  int befl = 0;
  int tmp=0;
  while(1)
  {
    if (l == n || r == n ) break;
    if (a[l] <= a[r]) 
    {
      tmp++;
      l++;
    }
    else 
    {
      cnt[tmp] = r-a[bef];
      r++;
    }
  }


}
