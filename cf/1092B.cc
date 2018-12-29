#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  vector<int> v;
  for (int i=0; i<n; i++)
  {
    int tmp;
    scanf("%d",&tmp);
    v.push_back(tmp);
  }
  sort(v.begin(),v.end());

  int ans=0;
  for (int i=0; i<n; i+=2)
  {
    ans += (v[i+1]-v[i]);
  }
  printf("%d\n", ans);
}
