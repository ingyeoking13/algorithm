#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int dx[4] ={-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int main()
{
  int T;
  cin >> T;
  while ( T-- )
  {
    set<string> myset;
    int col = 9, row = 5;
    char s[46];
    for (int i=0; i< 5; i++)
    {
      cin >> (s + i*col);
    }

    queue<pair<string, int>> q;
    myset.insert(string(s));
    q.push({string(s), 0});

    int mndist=1e9, mncnt=1e9;
    while( !q.empty() )
    {
      auto cur = q.front();
      string cur_state = cur.first;
      int d = cur.second;
      q.pop();

      char map[5][10];

      int cnt =0;
      for (int i=0; i<5; i++)
      {
        for (int j=0; j<9; j++)
        {
          map[i][j] = cur_state[i*9+j];
          if ( map[i][j] =='o' ) cnt++;
        }
        map[i][9] = 0;
      }

      if ( cnt < mncnt )
      {
        mncnt = cnt;
        mndist = d;
      }

      for (int i=0; i<5; i++)
      {
        for (int j=0; j<9; j++)
        {
          int x = i, y = j;
          if ( map[x][y] != 'o' ) continue; // check pegs. if pegs then go.

          for (int k=0; k<4; k++)
          {
            int nx = x+dx[k], ny = y+dy[k];
            if ( nx < 0 || ny < 0 || nx >= row || ny >= col ) continue;
            if ( map[nx][ny] == 'o' )
            {
              int nnx = nx+ dx[k] , nny = ny+dy[k];
              if ( nnx < 0 || nny < 0 || nnx >= row || nny >= col ) continue;
              if ( map[nnx][nny] !='.' ) continue;

              char new_map[5][10];
              for (int l=0; l<5; l++)
              {
                for (int m=0; m<9; m++)
                {
                  new_map[l][m] = map[l][m];
                }
              }

              new_map[x][y] = '.';
              new_map[nx][ny]='.';
              new_map[nnx][nny] = 'o';

              char new_state[46]; 
              for (int l=0; l<5; l++)
              {
                for (int m=0; m<9; m++)
                {
                  new_state[l*9+m] = new_map[l][m];
                }
              }
              new_state[45] = 0;

              string next = string(new_state);
              if ( myset.find(next) == myset.end() )
              {
                q.push(make_pair(next, d+1));
                myset.insert(next);
              }
            }
          }
        }
      }
    }
    cout << mncnt << " " << mndist << "\n";
  }
}
