#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
int main()
{
  int n;
  long long open[(int)2e5], close[(int)2e5];
  long long ans[(int)2e5];
  memset(ans, 0 ,sizeof(ans));

  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    scanf("%lld %lld", &open[i] , &close[i]);
  }
  sort(open, open+n);
  sort(close, close+n);

  int i=1, j=0;
  long long before = open[0];
  int cnt=1;
  while(i+1<n && open[i] == open[i+1]) 
  {
    i++;
    cnt++;
  };

  while( i<n && j< n)
  {
    for (int k=0; k<n; k++)
    {
      printf("%lld ", ans[k]);
    }
    printf("\n");
    int state=0, same=0;
    long long now;
    if ( open[i] < close[j] )
    {
      now = open[i];
      do{
        i++;
        state++;
      }while(i<n && now == open[i]);
    }
    else if ( open[i] == close[j] )
    {
      now = open[i];
      do {
        i++;
        state++;
      }while( i<n &&  now == open[i]);
      do {
        j++;
        state--;
      } while( j<n && now == close[j]);
      same=1;
    }
    else
    {
      now = close[j];
      do{
        j++;
        state--;
      }while(j<n && now == close[j]);
    }

    ans[cnt] += now - before;
    before = now;
    cnt += state;

    if ( same )
    {
      ans[cnt] += 1;
    }
  }

  while(j< n)
  {
    int state=0;
    long long now = close[j];
    do{
      j++;
      state--;
    }while(j<n && now == close[j]);
    ans[cnt] += now - before;
    before = now;
    cnt += state;
  }

  for (int i=0; i<n; i++)
  {
    printf("%lld ", ans[i]);
  }
  printf("\n");

}
