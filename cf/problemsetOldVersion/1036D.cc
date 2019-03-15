#include <stdio.h>

int a[(int)3e5], b[(int)3e5];
int main()
{

  int n, m;
  scanf("%d", &n);
  long long sum =0;
  for (int i=0; i<n; i++) 
  {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  scanf("%d", &m);
  for (int i=0; i<m; i++) 
  {
    scanf("%d", &b[i]);
    sum -= b[i];
  }

  if( sum != 0) return !printf("-1\n");

  int l =0, r=0;
  int ans = 0;
  long long lSum=a[0], rSum=b[0];

  for (; l<n && r<m; )
  {
    if ( lSum == rSum ) { 
      ans++; 
      lSum = rSum=0; 
      l++, r++;
      lSum += a[l], rSum += b[r];
    }
    else if ( lSum > rSum ) { r++;  rSum+= b[r];}
    else l++, lSum += a[l];
  }
  printf("%d\n", ans);
}


