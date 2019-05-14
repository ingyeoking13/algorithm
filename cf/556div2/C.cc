#include <iostream>

using namespace std;

bool np[(int)4e5+1];

int a[(int)2e5+1];
int d[(int)2e5+1];
int ans[(int)2e5+1];

int main()
{
  int n;
  cin >> n;

  for (int i=1; i<=n; i++) 
  {
    int tmp;
    cin >>  tmp ; 
    a[tmp]++;
  }

  np[1] = true;
  for (int i=2; i<=n; i++)
  {
    if ( np[i] ) continue;

    for (int j=2*i; j<=4e5; j+=i ) np[j] = true;
  }


  int cur = d[0];
  for (int i=1; i<=n; i++)
  {
    int next = cur+1;
    if ( np[next] == false )
    {
      if ( a[1] ) 
      {
        a[1]--;
        ans[i] = 1;
        cur = next;
        continue;
      }
    }

    next = cur+2;
    if ( np[next] == false )
    {
      if ( a[2] )
      {
        a[2]--;
        ans[i] = 2;
        cur = next;
        continue;
      }
    }

    if ( a[2] ) 
    {
      a[2] --;
      ans[i] =2;
      cur = next+2;
    }
    else 
    {
      a[1]--;
      ans[i] =1;
      cur = next+1;
    }
  }
  for (int i=1; i<=n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
