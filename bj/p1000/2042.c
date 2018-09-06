#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long a[(int)1e6]; 
long long* tree;

long long build_tree(int l, int r, int ti)
{
  if ( l == r) return tree[ti] = a[l];

  int m = (l+r)/2;
  long long lsum = build_tree(l, m, ti*2+1);
  long long rsum = build_tree(m+1, r, ti*2+2);
  return tree[ti]=lsum+rsum;
}

long long get_query(int ql, int qr, int ti, int tel, int ter)
{
  if (ql <= tel && ter <= qr ) return tree[ti];
  if (tel > qr || ter < ql ) return 0;
  int m = (tel+ter)/2;

  long long lstep = get_query(ql, qr, ti*2+1, tel, m);
  long long rstep = get_query(ql, qr, ti*2+2, m+1, ter);
  return lstep+rstep;
}

void switch_query(int idx, long long diff, int ti, int l, int r)
{
  if (l <= idx && idx <= r) tree[ti] -= diff;
  if ( l > idx ||  r < idx ) return;
  if ( l == r) return;

  int m = (l+r)/2;
  switch_query(idx, diff, ti*2+1, l, m);
  switch_query(idx, diff, ti*2+2, m+1, r);

}

int main(){
	int n, m, k ;
  scanf("%d %d %d", &n, &m, &k);

  int treesz = pow(2,ceil(log2(1e6))+1);
  tree = (long long*)malloc(sizeof(long long) * treesz);
  for (int i=0; i<n; i++)
    scanf("%lld", &a[i]);

  build_tree(0, n-1, 0);

  for (int i=0; i<m+k; i++)
  {
    int q;
    scanf("%d", &q);
    if (q==1)
    {
      int idx, to; scanf("%d %d", &idx, &to);
      switch_query(idx-1, a[idx-1]-to, 0, 0, n-1);
      a[idx-1] = to;
    }
    else
    {
      int l, r; scanf("%d %d", &l, &r);
      printf("%lld\n", get_query(l-1, r-1, 0, 0, n-1));
    }
  }
}
