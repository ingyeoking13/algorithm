#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int a[(int)1e3][(int)1e3];
int g1[(int)1e3][(int)1e3], g2[(int)1e3][(int)1e3];
int l1[(int)1e3][(int)1e3], l2[(int)1e3][(int)1e3];

int abs(int n) { return n>0?n:-n;};
int max(int x, int y) { return x>y?x:y;};
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++) scanf("%d", &a[i][j]);
  }

  for (int i=0; i<n; i++)
  {
    vector<int> v;
    for (int j=0; j<m; j++)
    {
      v.push_back(a[i][j]);
    }
    sort(v.begin(), v.end());
    int size = unique(v.begin(), v.end())- v.begin();
    for (int j =0; j<m; j++)
    {
      l1[i][j] = lower_bound(v.begin(), v.begin()+ size, a[i][j]) - v.begin();
      g1[i][j] = size- l1[i][j];
    }
  }

  for (int i=0; i<m; i++)
  {
    vector<int> v;

    for (int j=0; j<n; j++)
    {
      v.push_back(a[j][i]);
    }
    sort(v.begin(), v.end());
    int size = unique(v.begin(), v.end()) - v.begin();
    for (int j =0; j<n; j++)
    {
      l2[j][i] = lower_bound(v.begin(), v.begin()+size, a[j][i]) - v.begin();
      g2[j][i] = size - l2[j][i];
    }
  }
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      printf("%d ", max(g1[i][j], g2[i][j]) + max(l1[i][j], l2[i][j]));
    }
    printf("\n");
  }
}
