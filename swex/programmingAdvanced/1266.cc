#include <iostream>

using namespace std;
int a[7] = {2, 3, 5, 7, 11, 13, 17};
double power(double init, int n)
{
  double ret =1;
  double cur = init;
  while ( n )
  {
    if ( n%2 ) 
    {
      ret *= cur;
      n--;
    }
    cur*=cur;
    n/=2;
  }
  return ret;
};

long long d[19][19];

int main()
{

  int tt=0;
  int T;
  cin >> T;
  d[0][0]= 1;

  for (int i=1; i<=18; i++)
  {
    d[i][0] = 1;
    for (int j=1; j<=i; j++)
    {
      d[i][j] = d[i-1][j-1] + d[i-1][j];
    }
  }

  while (++tt <= T)
  {
    double p, pp;
    cin >> p >> pp;
    p /=100;
    pp /= 100;

    double ans[7][2];
    for (int i=0; i<7; i++)
    {
      ans[i][0] = power(p, a[i])*power(1-p, 18-a[i]);
      ans[i][0] *= d[18][a[i]];
      ans[i][1] = power(pp, a[i])*power(1-pp, 18-a[i]);
      ans[i][1] *= d[18][a[i]];
    }

    double aans =0;
    for (int i=0; i<7; i++)
    {
      aans += ans[i][0];
      aans += ans[i][1];
    }
    for (int i=0; i<7;  i ++)
    {
      for (int j=0; j<7; j++)
      {
        aans -= ans[i][0]*ans[j][1];
      }
    }

    printf("#%d %.6lf\n", tt, aans);
  }
}
