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
        r[i][j] = c[i][j] = d[i][j]=0;
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

    vector<rect> ans;
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
          ans.push_back(rect(r[k][j-1], c[k][j-1]));
        }
      }
    }
    sort(ans.begin(), ans.end(), mycmp);
    cout << "#" << tt << " " << ans.size() << " ";
    for (int i=0; i<ans.size(); i++)
    {
      cout << ans[i].row << " " << ans[i].col << " ";
    }
    cout << "\n";
  }
}
