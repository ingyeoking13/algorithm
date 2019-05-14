#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[101];
vector<int> b;
int main()
{
  int n, k;
  cin >> n >> k;

  int cnt=0;
  for (int i=0; i<n; i++)
  {
    cin >> a[i];
    if ( a[i] == 0 ) cnt ++;
  }

  for (int i=0; i<k; i++)
  {
    int tmp;
    cin >> tmp;
    b.push_back(tmp);
  }

  if ( cnt > k )
  {
    cout << "No\n";
    return 0;
  }

  if ( cnt >= 2 )
  {
    cout << "Yes\n";
    return 0;
  }

  for (int i=1; i<n; i++)
  {
    if ( a[i-1] == 0 && a[i] > 0 )
    {
      for (int j=0; j<k; j++)
      {
        if ( b[j] > a[i] ) 
        {
          cout << "Yes\n";
          return 0;
        }
      }
    }

    if ( a[i-1] > 0  && a[i] == 0 )
    {
      for (int j=0; j<k; j++)
      {
        if ( b[j] < a[i-1] ) 
        {
          cout << "Yes\n";
          return 0;
        }
      }
    }

    if ( a[i-1] > 0 && a[i] > 0 )
    {
      if ( a[i-1] > a[i] )
      {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";


}
