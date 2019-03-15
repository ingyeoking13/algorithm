#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char s[501];
int d[500][500];

int main()
{
  int n;
  scanf("%d", &n);
  scanf("%s", s);

  memset(d, 0x7f, sizeof(d));

  for (int i=0; i<n; i++) d[i][i] = 1;

  for (int i=0; i<n-1; i++)
  {
    if ( s[i] == s[i+1] ) d[i][i+1] =1;
    else d[i][i+1] =2;
  }

  for (int len=3; len<=n; len++)
  {

    for (int left=0; left<n; left++)
    {
      int right = left + len - 1;

      if ( s[left] == s[right] )
      {
        d[left][right] = 
          min(d[left+1][right-1]+1, d[left][right-1]+1);
        d[left][right] = min(d[left][right], d[left+1][right]+1);
      }
      else
      {
        d[left][right] = min (d[left][right-1]+1, d[left+1][right] +1);
      }
    }
  }
  for (int i=0; i<n; i++)
  {
    printf("%d\n", d[0][i]);
  }

}
