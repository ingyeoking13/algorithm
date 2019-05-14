#include <iostream>
#include <vector>

using namespace std;

int a[1000], b[1000];
int ans[1000];
int acnt[1001], bcnt[1001];

vector<int> aa, bb;
int main()
{
  int n;
  cin >> n;
  int x=-1, y=-1;
  for (int i=0; i<n; i++) 
  {
    cin >> a[i];
    if ( acnt[a[i]] ) x = a[i];
    acnt[a[i]]=1;
  }
  for (int i=0; i<n; i++) 
  {
    cin >> b[i];
    if ( bcnt[b[i]] ) y = b[i];
    bcnt[b[i]]=1;
  }

  for (int i=0; i<n; i++)
  {
    if ( a[i] == x ) aa.push_back(i);
    if ( b[i] == y ) bb.push_back(i);
  }

  for (int i=0; i<n; i++)
  {
    if ( aa[0] != i && aa[1] != i ) ans[i] = a[i];
    if ( bb[0] != i && bb[1] != i ) ans[i] = b[i];
  }

  for (int i=1; i<=n; i++) acnt[i] =0;

  for (int i=0; i<n; i++)
  {
    acnt[ ans[i] ]++;
  }

  vector<int> rep;
  for (int i=1; i<=n; i++)
  {
    if (acnt[i] == 0) rep.push_back(i);
  }

  if ( rep.size() > 0 )
  {
    for (int i=0; i<n; i++)
    {
      if ( ans[i] == 0)
      {
        cout << rep[0] << " ";
        rep.erase(rep.begin());
      }
      else cout << ans[i] << " ";
    }
  }
  else 
  {
    for (int i=0; i<n; i++)
    {
      cout << ans[i] << " ";
    }
  }
}
