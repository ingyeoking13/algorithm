#include <stdio.h>
//#include <unistd.h>
#include <vector>
using namespace std;

long long max(long long a, long long b) { return a<b?b:a; }
pair<int,int> min(pair<int,int> a, pair<int,int> b) { return (a.first<b.first?a:b); }
int cnt=0;

pair<int, int> segbuild(int l, int r, int* a, int idx, pair<int,int>* mnseg)
{
  cnt++;
  if (l == r) return mnseg[idx] = { a[l], l }; 
    
  return 
      mnseg[idx] = min(
      segbuild(l, (r+l)/2, a, idx*2+1, mnseg), 
      segbuild((r+l)/2+1, r, a, idx*2+2, mnseg)
      );
}

pair<int, int> segquery(int l, int r, pair<int,int>* mnseg, int idxl, int idxr, int idx)
{
  if ( l <= idxl && idxr <= r ) return mnseg[idx]; 
  if ( l > idxr || r < idxl ) return make_pair((int)1e9+1, -1);
  return min(segquery(l, r, mnseg, idxl, (idxr+idxl)/2, idx*2+1), segquery(l, r, mnseg, (idxl+idxr)/2+1, idxr, idx*2+2));
}

long long maxRect(int l, int r, pair<int, int>* mnseg, int n)
{
  if (l> r) return -1;

//  printf("%d %d %d %d %d\n", l, r, 0, n, 0);
  //sleep(3);
  pair<int, int> q = segquery(l, r, mnseg, 0, n, 0);
  //printf("===%d %d\n", q.first, q.second);

  long long ret = (long long)q.first * (r-l+1);

  ret = max(ret, maxRect(l, q.second-1 ,mnseg, n));
  ret = max(ret, maxRect(q.second+1, r,  mnseg, n));
  return ret;
}

int main()
{
  int n;
  while(scanf("%d", &n))
  {
    if (n==0) break;

    int a[(int)1e5];
    pair<int, int> mnseg[4*(int)1e5];

    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    segbuild(0, n-1, a, 0, mnseg);
    printf("%lld\n", maxRect(0, n-1, mnseg, n-1));
  }

}
