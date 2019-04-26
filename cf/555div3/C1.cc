#include <iostream>
#include <vector>

using namespace std;

int a[(int)2e5];
int main()
{
  int n;
  cin >> n;

  for (int i=0; i<n; i++) cin >> a[i];

  int l = 0 , r = n-1;
  int cur = -1;

  vector<char> ans;

  while ( l<=r )
  {
    int prev = cur;
    int left = a[l];
    int right = a[r];

    int next = 2e9;

    if ( prev < left ) next = left;
    if ( prev < right && next > right ) next = right; 

    if ( next == 2e9 )
    {
      break;
    }

    cur = next;
    if ( next == left ) 
    {
      ans.push_back('L');
      l++;
    }
    else 
    {
      ans.push_back('R');
      r--;
    }
  }
  cout << ans.size() <<"\n";
  for (int i=0; i<ans.size(); i++)
  {
    cout << ans[i];
  }
  cout << "\n";
}
