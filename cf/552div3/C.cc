#include <stdio.h>
#include <algorithm>

using namespace std;

int days[7] = { 0, 1, 2, 0, 2, 1, 0};
int a[3];
int main()
{
  for (int i=0; i<3; i++) scanf("%d", &a[i]);
  int aa = a[0]/3, bb = a[1]/2, cc = a[2]/2;

  int week = min(aa, bb);
  week = min(week, cc);
  a[0] -= week*3, a[1] -= week*2, a[2] -= week*2;
  int ans = week*7;

  int mx = 0;
  for (int i=0; i<7; i++)
  {
    int b[3];
    for (int j=0; j<3; j++) b[j]=a[j];

    for (int j=0; j<7; j++)
    {
      int d = (i+j)%7;
      if (b[days[d]]>0) b[days[d]]--;
      else 
      {
        mx = max(j, mx);
        break;
      }
    }
  }

  printf("%d\n", ans + mx);

}
