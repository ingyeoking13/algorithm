#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct rect
{
  int row, col;
  rect(int row, int col) : row(row), col(col) {};
};

bool mycmp(const rect& a, const rect& b)
{
  if ( a.row*a.col == b.row*b.col ) return a.row < b.row;
  return a.row*a.col < b.row*b.col;
};

vector<int> edge[20];
int series[20];
int _series[20];
bool visit[20];
int mx;

void go(int now, int depth )
{
  if ( mx < depth )
  {
    mx = depth;
    for (int i=0; i<depth; i++) series[i]=_series[i];
  }

  for (int i=0; i< edge[now].size(); i++)
  {
    int j = edge[now][i];
    if ( visit[ j ] ) continue;
    _series[depth] = j;
    visit[j] = true;
    go(j, depth+1);
    visit[j] = false;
  }
}

int main()
{
  int tt=0;
  int T;
  cin >> T;
  int a[102][102], r[102][102], c[102][102];
  bool d[102][102];

  while (++tt<=T)
  {

    int n;
    cin >> n;
    for (int i=0; i<=101; i++)
    {
      for (int j=0; j<=101; j++)
      {
        a[i][j] = r[i][j] = c[i][j] = d[i][j] = 0;
      }
    }

    for (int i=1; i<=n; i++)
    {
      for (int j=1; j<=n; j++)
      {
        cin >> a[i][j];
      }
    }

    for (int i=1; i<=n; i++)
    {
      for (int j=1; j<=n; j++)
      {
        if ( a[i][j] ) c[i][j] = c[i][j-1]+1;
        else c[i][j] = 0;

        if ( a[j][i] ) r[j][i] = r[j-1][i]+1;
        else r[j][i] = 0;
      }
    }

    vector<rect> matrix;
    bool state = false;
    for (int i=1; i<=n+1; i++)
    {
      for (int j=1; j<=n+1; j++)
      {
        if ( c[i][j] ) state=true;
        else if ( state )
        {
          state= false;
          int k = i;
          while ( a[k][j-1] ) k++;
          k--;
          if ( d[k][j-1] ) continue;
          d[k][j-1]= true;
          matrix.push_back(rect(r[k][j-1], c[k][j-1]));
        }
      }
    }

    for (int i=0; i<20; i++ ) 
    {
      edge[i].clear();
      visit[i] = false;
    }
    mx=0;

    n = matrix.size();

    for (int i=0; i<n; i++)
    {
      for (int j=i+1; j<n; j++)
      {
        if ( matrix[i].col == matrix[j].row ) edge[i].push_back(j);
        if ( matrix[j].col == matrix[i].row ) edge[j].push_back(i);
      }
    }

    for (int i=0; i<n; i++)
    {
      _series[0] = i;
      visit[i] = true;
      go(i, 1);
      visit[i] = false;
    }

    int d[20][20];
    for (int i=0; i<n; i++) d[i][i] = 0;

    for (int len=2; len<=n; len++)
    {
      for (int i=0; i<=n-len; i++)
      {
        int j = i + len-1;
        d[i][j] = 2e9;
        for (int k=i; k<= j-1; k++)
        {
          int tmp = d[i][k] + d[k+1][j] + matrix[series[i]].row*matrix[series[k]].col*matrix[series[j]].col;
          if ( tmp < d[i][j] ) d[i][j] = tmp;
        }
      }
    }

    cout << "#" << tt << " " << d[0][n-1] << "\n";
  }
}
