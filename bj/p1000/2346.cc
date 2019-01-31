#include <iostream>
#include <vector>

using namespace std;
vector<int> a;
vector<bool> chk;

int safe(int number, int mx)
{
  if ( number >0 ) return number%mx;
  else return (mx*1000+number)%mx;
}


int main()
{
  int n;
  cin >> n;

  a.resize(n);
  chk.resize(n, false);

  for (int i=0; i<n; i++) cin >> a[i];

  int next = 0;
  vector<int> ans;
  ans.push_back(1);

  for (int i=0; i<n-1; i++)
  {
    int now  = next;
    chk[now]=1;

    int rem = 0;
    int j;

    if ( a[now] >= 0)
    {
      for ( j=1; j<= a[now]+rem; j++)
      {
        if ( chk[safe(j+now,n)] ) 
        {
          rem++;
        }
      }
      j--;
    }
    else
    {
      for (j =-1; j>= a[now]+rem; j--)
      {
        if ( chk[safe(j+now,n)] ) rem--;
      }
      j++;
    }
    next = safe(j+now, n);
    ans.push_back(next+1);
  }
  for (auto i: ans) cout << i << " ";

}
