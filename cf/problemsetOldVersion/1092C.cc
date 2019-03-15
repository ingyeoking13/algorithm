#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<string> vs;
int n;

void Do(string str)
{
  vector<bool> chk(n, false);
  string ans;
  for (int i=0; i<n; i++)
  {
    if ( chk[vs[i].size()-1]==0 && (int)str.find(vs[i]) == 0)
    {
      ans += "P";
      chk[vs[i].size()-1]=1;
    }
    else if ( str.substr( str.size() -vs[i].size()) == vs[i]) 
    {
      ans += "S"; 
    }
    else return;
  }
  cout << ans << "\n";
  exit(0);
}

int main()
{
  int len;
  cin >> len;
  n=2*len-2;

  string pre, suf;
  vs.resize(n);

  for (int i=0; i<n; i++)
  {
    cin >> vs[i];
    if (vs[i].size() == len-1 && pre.size() == 0 ) pre = vs[i];
    else if (vs[i].size() == len-1) suf=vs[i];
  }
  Do(pre + suf.back());
  Do(suf + pre.back());
}
