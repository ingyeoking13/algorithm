#include <iostream>

using namespace std;
bool p[(int)1e5+1];

int main()
{
  //freopen("in.txt", "r", stdin);

  for (int i=2; i<=1e5; i++)
  {
    p[i]=1;
  }

  for (int i=2; i<=1e5; i++)
  {
    if (p[i])
    {
      for (int j=i+i; j<=1e5; j+=i)
      {
        p[j]=0;
      }
    }
  }

  long long n;
  cin >> n;
  long long ans=0;

  while(n!=0)
  {
    bool chk=0;
    if (n%2 == 0) 
    {
      ans = ans+ ((long long)n)/2; 
      chk=1;
      break;
    }

    for (long long i=2; i*i<=n; i++)
    {
      if (n%i == 0)
      {
        if (p[i])
        {
          n-=i;
          chk=1;
          ans++;
          break;
        }
      }
    }

    if (!chk) 
    {
      ans++;
      break;
    }
  }
  cout << ans <<"\n";
}
