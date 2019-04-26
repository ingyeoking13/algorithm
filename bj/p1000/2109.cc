#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> a[(int)1e4+1];
int d[(int)1e4];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++) 
  {
    int p, day;
    scanf("%d %d", &p, &day);

    a[day].push_back(p);
  }

  for (int i=1; i<=1e4; i++) sort(a[i].begin(), a[i].end());

  priority_queue<int> ans;
  long long aa=0;
  for (int i=1; i<=1e4; i++)
  {

    for (int j=0; j<a[i].size(); j++)
    {
      aa+= a[i][j];
      ans.push(-a[i][j]);
      if (ans.size() > i ) 
      {
        aa += ans.top();
        ans.pop();
      }
    }
  }

  printf("%lld\n", aa);
}
