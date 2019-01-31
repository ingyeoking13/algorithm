#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> segTree[(int)(4e5)];

void buildTree(vector<int>& a, int l, int r, int nowIdx)
{
  if ( l == r ) 
  {
    segTree[nowIdx].push_back(a[l]);
    return;
  }

  int mid = (l+r)/2;
  buildTree(a, l, mid, nowIdx*2+1);
  buildTree(a, mid+1, r, nowIdx*2+2);

  int i=0, j=0;
  while ( i < segTree[nowIdx*2+1].size() && j < segTree[nowIdx*2+2].size() )
  {

    int ll  = segTree[nowIdx*2+1][i], rr = segTree[nowIdx*2+2][j];
    if ( ll > rr )
    {
      segTree[nowIdx].push_back(rr);
      j++;
    }
    else
    {
      segTree[nowIdx].push_back(ll);
      i++;
    }
  }
  while( i <segTree[nowIdx*2+1].size() ) 
    segTree[nowIdx].push_back(segTree[nowIdx*2+1][i++]);
  while( j <segTree[nowIdx*2+2].size() ) 
    segTree[nowIdx].push_back(segTree[nowIdx*2+2][j++]);
}

int query(int ql, int qr, int nowl, int nowr, int nowIdx, int k)
{
  if ( qr < nowl || nowr < ql ) { return 0; }

  if ( ql <= nowl  && nowr <= qr ) 
  {
    int l=0, r = segTree[nowIdx].size()-1;
    int cnt =0;

    while( l <= r )
    {
      int mid = (l+r)/2;

      if ( segTree[nowIdx][mid] > k )
      {
        cnt = segTree[nowIdx].size() - mid;
        r = mid-1;
      }
      else l = mid+1;
    }

    return cnt;
  }

  int mid = (nowl+nowr)/2;
  return query(ql, qr, nowl, mid, nowIdx*2+1, k) + 
         query(ql, qr, mid+1, nowr, nowIdx*2+2, k);
}

int main()
{
  int n;
  scanf("%d", &n);

  vector<int> a;
  a.resize(n);
  for (int i=0; i<n; i++) scanf("%d", &a[i]);

  buildTree(a, 0, n-1, 0);
  int m;
  scanf("%d", &m);
  while(m--)
  {
    int ql, qr, k;
    scanf("%d%d%d", &ql, &qr, &k);
    ql--, qr--;
    printf("%d\n",query(ql, qr, 0, n-1, 0, k));
  }
}
