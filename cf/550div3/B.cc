#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> odd, even;
int main()
{
  int  n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    int tmp;
    scanf("%d", &tmp);

    if ( tmp % 2 == 1 ) odd.push_back(-tmp);
    else even.push_back(-tmp);
  }

  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());

  int i=0, j= 0;
  while ( i<odd.size() && j < even.size() )
  {
    i++, j++;
  }

  i++, j++;
  int ans=0;
  for (;i<odd.size();i++)
  {
    odd[i] = -odd[i];
    ans += odd[i];
  }

  for (;j<even.size();j++)
  {
    even[j] = -even[j];
    ans += even[j];
  }
  printf("%d\n", ans);

}
