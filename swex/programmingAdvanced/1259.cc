#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct vertex
{
  int in, out;
  vertex() {};
  vertex(int in, int out) : in(in), out(out) { }
};

bool visit[20];
int ans[20], route[20];
int mx, n;
vector<int> edge[20];
vertex a[20];

void go (int now, int depth)
{
  if ( depth > mx )
  {
    mx = depth;
    for (int i=0; i<depth; i++) ans[i] = route[i];
  }

  for (int i= 0; i<edge[now].size(); i++)
  {
    int j = edge[now][i];
    if( visit[j] ) continue;
    route[depth] = j;
    visit[j] = true;
    go(j, depth+1);
    visit[j] = false;
  }
}

int main()
{
  int T ;
  int tt = 0;
  cin >> T;
  while ( ++ tt <= T )
  {
    mx = 0;
    cin >> n;
    for (int i=0; i<20 ;i ++ ) edge[i].clear();
    for (int i=0; i<n; i++) cin >> a[i].out  >> a[i].in;

    for (int i=0; i<n; i++)
    {
      for (int j=i+1; j<n; j++)
      {
        if ( a[i].out == a[j].in ) edge[j].push_back(i);
        if ( a[j].out == a[i].in ) edge[i].push_back(j);
      }
    }

    for (int i=0; i<n; i++)
    {
      visit[i] = true;
      route[0] = i;
      go(i, 1);
      visit[i] = false;
    }
    cout << "#" << tt << " ";
    for (int i=0; i<n; i++) cout << a[ans[i]].out << " " << a[ans[i]].in << " ";
    cout << "\n";
  }
}
