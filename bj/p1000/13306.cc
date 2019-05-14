#include <iostream>
#include <stack>

using namespace std;

int in[(int)2e5];
struct data
{
  int type, u ,v ;
  data(int type, int u, int v ) : type(type), u(u), v(v) {};
};

stack<data> in2;
int p[(int)2e5];

int ufind(int a)
{
  if (a == p[a] ) return a;
  return p[a] = ufind(p[a]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n  >> q;

  p[0] = 0;
  for (int i=1; i<n; i++)
  {

    int v;
    cin >> v;
    v--;
    in[i] = v;

    p[i] = i;
  }

  q = n-1+q;
  while ( q-- )
  {
    int type;
    cin >> type;
    if (type == 0)
    {
      int u;
      cin >> u;
      u--;
      in2.push(data(type, u, 1));
    }
    else 
    {
      int u, v;
      cin >> u >> v;
      u-- , v--;
      in2.push(data(type, u, v));
    }
  }

  stack<bool> ans;
  while( !in2.empty() )
  {
    data now = in2.top();
    in2.pop();
    int u = now.u, v = now.v; 

    if (now.type == 0)
    {
      p[u] = in[u];
    }
    else
    {
      u = ufind(u), v= ufind(v);
      if ( u== v ) ans.push(true);
      else ans.push(false);
    }
  }

  while(!ans.empty())
  {
    bool cur = ans.top();
    ans.pop();
    if ( cur ) cout << "YES\n";
    else cout << "NO\n";
  }
}
