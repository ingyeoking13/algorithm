#include <iostream>

using namespace std;
int a[(int)1e6];
int tree[(int)4e6];

int init(int l, int r, int idx)
{
if ( l == r) return tree[idx] = a[l];
int m = (l+r)/2;
return tree[idx] = max(init(l, m, idx*2+1), init(m+1, r, idx*2+2));
}

int query(int l, int r, int idx, int ql, int qr)
{
if ( ql<= l && r <= qr ) return tree[idx];
if ( qr < l ||  ql > r ) return 0;

int m = (l+r)/2;
return max(query(l, m, idx*2+1, ql, qr), query(m+1, r, idx*2+2, ql, qr));
}

int main(void) 
{
int n;
cin >> n;
for (int i=0; i<n; i++) cin >> a[i];
init(0, n-1, 0);

int ans = 1;
for (int i=0; i<n; i++)
{
int temp=-1 ;
for (int j=i+2; j<n; j++)
{
int height = query(0, n-1, 0, i+1, j-1);
if ( height < a[j] && height < a[i]) 
{
ans = max(ans, j-i);
temp = j;
}
else  break;
}
if ( temp >i) i = temp-1;
}
cout << ans << "\n";
return 0;
}
