#include <stdio.h>
#include <string.h>

char query[10];
int n;
int prev[(int)1e3+1], next[(int)1e3+1];
int main()
{
  scanf("%d%s", &n,query);

  for (int i=0; i<n; i++) prev[i] = i;
  int k = strlen(query);

  int ans=0;
  while(1)
  {

    int m;
    if ( k == 2 ) // in 
    {
      m = n/2;
      for (int i=0; i<m; i++) next[i*2+1] = prev[i];
      for (int i=m, j =0; i<n; i++,j++) next[j*2] = prev[i];
    }
    else // out 
    {
      m = (n+1)/2;
      for (int i=0; i<m; i++) next[i*2] = prev[i];
      for (int i=m, j =0; i<n; i++, j++) next[j*2+1] = prev[i];
    }

    ans++;

    bool chk=true;
    for (int i=0; i<=m; i++)
    {
      if ( next[i] != i ) 
      {
        chk= false;
        break;
      }
    }

    if ( chk ) return !printf("%d\n", ans);
    for (int i=0; i<n; i++) prev[i] = next[i];
  }

}
