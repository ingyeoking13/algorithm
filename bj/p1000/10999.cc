#include <stdio.h> 

long long a[ (int)1e6 ], segVal[(int)4e6],  segLazy[(int)4e6];

long long init(int l, int r, int idx)
{
  if ( l == r) return segVal[ idx ] = a[ l ];
  int m = (l+r)/2;
  return segVal[idx] = init (l,m,idx*2+1) + init(m+1,r,idx*2+2);
};

void update_lazy(int l, int r, int idx)
{
  if( segLazy[ idx] != 0)
  {
    segVal[idx] += (r-l+1)*segLazy[idx];
    if ( l != r )
    {
      segLazy[idx*2+1] += segLazy[idx];
      segLazy[idx*2+2] += segLazy[idx];
    }
    segLazy[idx] = 0;
  }
}

void update(int ql, int qr, int l, int r, int idx, long long& val)
{
  update_lazy(l, r, idx);

  if ( ql <= l && r <= qr ) 
  {
    segVal[idx] += val*(r-l+1);
    if ( l != r )
    {
      segLazy[ idx*2+1 ] += val; 
      segLazy[ idx*2+2 ] += val;
    }
    return ;
  }

  if ( ql > r || l > qr ) return;

  int m = (l+r)/2;
  update( ql, qr, l, m, idx*2+1, val);
  update( ql, qr, m+1, r, idx*2+2, val);
  segVal[idx] = segVal[idx*2+1] + segVal[idx*2+2]; 
};

long long get(int ql, int qr, int l, int r, int idx)
{
  update_lazy(l, r, idx);

  if ( l > qr || r < ql ) return 0;

  if ( ql <= l && r <= qr ) return segVal[idx];
  int m = (l+r)/2;
  return get(ql, qr, l, m , idx*2+1) + get (ql, qr, m+1, r, idx*2+2);
};

int main()
{
  int n, m, k;
  scanf("%d%d%d\n", &n, &m, &k);
  for (int i=0; i<n; i++) scanf("%lld", &a[i]);

  m+=k;
  init(0, n-1, 0);

  while(m--)
  {
    int q;
    scanf("%d", &q);

    if ( q == 1 )
    {
      int ql, qr;  long long val; 
      scanf("%d%d%lld", &ql, &qr, &val);
      ql--, qr--;
      update(ql, qr, 0, n-1, 0, val);
    }
    else
    {
      int ql, qr; 
      scanf("%d%d", &ql, &qr);
      ql--, qr--;
      printf("%lld\n", get(ql, qr, 0, n-1, 0));
    }
  }
}
