#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{

  int n, v;
  scanf("%d%d", &n, &v);

  int now =1;
  int cur =0;
  int ans =0;

  while(true)
  {
    if ( now <  n )
    {
      int dist = n-now;
      if ( cur < dist ) 
      {
        int buy = min(dist , v-cur);
        ans += buy*now;
        cur += buy;
      }

      now++;
      cur--;
    }
    else break;

  }
  printf("%d\n", ans);
}
