#include <stdio.h>
#include <vector>
using namespace std;

int hit[(int)2e5+1];
int a[(int)2e5+1];
int main()
{

  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    hit[a[i]]++;
  }

  int target;
  int mx =0;
  for (int i=0; i<=2e5; i++)
  {
    if ( hit[a[i]] > mx ) 
    {
      target =a[i];
      mx = hit[a[i]];
    }
  }

  int ans = n-mx;
  printf("%d\n", ans);

  vector<int> tv;
  for (int i=0; i<n; i++)
  {
    if ( a[i] == target ) tv.push_back( i );
  }

  for (int i=0; i<tv.size(); i++)
  {
    //left 
    int cur = tv[i];
    while ( cur -1 >=0 && a[ cur-1 ] != target )
    {
      int nval = a[cur-1];
      if ( nval > a[cur] )
      {
        printf("2 %d %d\n", cur-1 +1, cur + 1);
      }
      else 
      {
        printf("1 %d %d\n", cur-1 +1, cur +1);
      }
      a[cur-1] = target;
      cur = cur-1;
    }

    cur = tv[i];
    while ( cur +1 <n && a[cur+1] != target)
    {
      int nval = a[cur+1];
      if ( nval > a[cur] )
      {
        printf("2 %d %d\n", cur+1 +1, cur +1);
      }
      else printf("1 %d %d\n", cur+1 +1, cur +1);
      a[cur+1] = target;
      cur = cur+1;
    }
  }
}
