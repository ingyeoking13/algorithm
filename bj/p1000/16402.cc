#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <string>
#include <map>

using namespace std;

map<string, string> p; 

string ufind(string a)
{
  if ( p[a] == a) return p[a];
  else return p[a] = ufind(p[a]);
}

int main()
{
  int n, m;
  cin >> n >> m;
  cin.ignore();
  vector<string> kingdom;
  
  for (int i=0; i<n; i++)
  {
    string tmp;
    getline(cin, tmp);
    p.insert(make_pair(tmp, tmp));
  }

  vector<string> vs;
  for (int i=0; i<m; i++)
  {
    string tmp;
    getline(cin, tmp);

    istringstream input(tmp);
    int cnt=0;
    string token;
    while(getline(input, token, ',')) vs.push_back(token);
  }

  for (int i=0; i<vs.size()/3; i++)
  {
    string u= vs[i*3];
    string v= vs[i*3+1];
    int win = (vs[i*3+2]=="1"?1:2);

    string pu = ufind(u), pv = ufind(v);
    if ( pu == pv)
    {
      if (pu == u && win==2)
      {
        p[pu] = v; 
        p[v] = v;
      }
      else if ( pv == v && win==1 )
      {
        p[pv] = u;
        p[u] = u;
      }
      continue;
    }

    if ( win == 1) p[pv] = u; 
    else p[pu] = v;
  }

  vector<string> ans;
  for (auto i: p)
  {
    if (i.first == i.second )  ans.push_back(i.first);
  }

  cout << ans.size() << "\n";
  for (auto i : ans)
  {
    cout << i << "\n";
  }
}
