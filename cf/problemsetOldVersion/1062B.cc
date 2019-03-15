#include <stdio.h>
#include <vector>

using namespace std;
int main()
{
  int n; scanf("%d", &n);
  int ori=n;

  vector<int> div(n+1, 0);

  int i=2;
  while(ori!=1)
  {
    if (ori%i==0)
    {
      div[i]++;
      ori/=i;
    }
    else i++;
  }

  int mx=0;
  bool chk=false;
  for (int i=0; i<=n; i++)
  {
    if (div[i] == 0) continue;

    mx = max(mx, div[i]);
    if (div[i] >1) chk=true;
    //printf("%d %d\n",i, div[i]);
  }

  if (!chk) 
  {
    return !printf("%d 0\n", n); 
  }

  int minpower;
  for (minpower=2; minpower<mx; minpower*=2);

  chk=false;
  for (int i=2; i<=n; i++)
  {
    if (div[i] == 0) continue;
    if (div[i] < minpower)
    {
      div[i] += (minpower - div[i]);
      chk=true;
    }
  }

  int val=1;
  int ans=(chk?1:0);

  while(minpower!=1) minpower/=2, ans++;

  for (int i=2; i<=n; i++)
  {
    if (div[i])
    {
      val*=i;
    }
  }
  printf("%d %d\n", val, ans);

}
