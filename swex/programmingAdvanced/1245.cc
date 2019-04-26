#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long double abs(long double a)
{
  if (a<0) return -a;
  return a;
}
int main()
{
  int T;
  int test_case=0;
  scanf("%d", &T);

  while(test_case++ < T)
  {
    int n; 
    scanf("%d", &n);

    pair<int, int> a[(int)1e5];
    for (int i=0; i<n; i++) 
    {
      scanf("%d", &a[i].first);
    }
    for (int i=0; i<n; i++) scanf("%d", &a[i].second);

    sort(a, a+n);
    vector<long double> ans;

    bool chk=false;
    for (int i=0; i<n-1; i++)
    {
      chk= false;
      long double l = a[i].first+1e-15, r = a[i+1].first-1e-15;

      while( l<= r)
      {
        long double mid = (l+r)/2;
        bool hit = false;
        long double totalForce = 0;

        for (int j=0; j<n; j++)
        {
          long double dist = ((long double)abs(a[j].first-mid))* abs(a[j].first-mid);

          if (dist == 0) continue;
          long double force = ((long double)a[j].second)/dist;
          totalForce += (force *(int)(mid>a[j].first?-1:1));
        }

        if((int)(totalForce/(1e-12)) == 0)
        {
          chk = true;
          ans.push_back(mid);
          break;
        }
        else if ( totalForce <0) l = mid+1e-15;
        else r = mid-1e-15;
      }
    }

    /*
    for (int i=0; i<n; i++)
    {
      int x = a[i].first;
      double totalForce = 0;
      for (int j=0; j<n; j++)
      {
        long long dist = ((long long)abs(a[j].first-x))* abs(a[j].first-x);
        if ( dist == 0) continue;

        double force = ((double)a[j].second)/dist;
        totalForce += force *(x>a[j].first?-1:1);
      }

      if( totalForce == 0) ans.push_back(x);
    }
    */
    printf("#%d ", test_case);
    for (int i=0; i<ans.size(); i++) printf("%.10Lf ", ans[i]);
  }
}
