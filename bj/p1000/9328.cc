#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

char map[100][101];
char visit[100][100];
int dx[4] ={ 0, 0, -1, 1};
int dy[4] ={-1, 1, 0, 0};

struct pos { 
  int x, y; 
  pos(int x, int y) : x(x), y(y) {}
};

int main()
{
  int T; 
  scanf("%d", &T);

  while(T--)
  {
    memset(visit, 0, sizeof(visit));
    int n, m; 
    scanf("%d %d", &n, &m);

    for (int i=0; i<n; i++)
    {
      scanf("%s", map[i]);
    }

    char keystr[200];
    scanf("%s", keystr);

    queue<pos> q;
    vector<vector<pos>> door;
    vector<bool> keychk;
    door.resize(26);
    keychk.resize(26);

    if (keystr[0] == '0');
    else 
    {
      int len = strlen(keystr);
      for (int i=0; i<len; i++)
      {
        keychk[keystr[i]-'a']=1;
      }
    }

    int ans=0;

    for (int i=0; i<n; i++)
    {
      for (int j=0; j<m; j++)
      {
        if (i==0 || j==0 || i==n-1 || j==m-1)

        {
          if ( map[i][j] == '.') 
          {
            q.push({i,j});
            visit[i][j]=1;
          }
          else if ( 'a'<= map[i][j] && map[i][j] <='z' )
          {

            q.push({i,j});
            visit[i][j]=1;
            
            if (!keychk[map[i][j]-'a'])
            {
              for (int k=0; k< door[map[i][j]-'a'].size(); k++)
              {
                q.push(door[map[i][j]-'a'][k]);
              }
              door[map[i][j]-'a'].clear();
            }
            keychk[map[i][j]-'a']=1;

          }
          else if ('A' <= map[i][j] && map[i][j] <= 'Z' )
          {
            visit[i][j]=1;

            if (!keychk[map[i][j]-'A'])
            {
              door[map[i][j]-'A'].push_back({i,j});
            }
            else q.push({i,j});

          }
          else if ( map[i][j] =='$' )
          {
            visit[i][j]=1;
            ans++;
            q.push({i,j});
          }
        }
      }
    }
    
    while(!q.empty())
    {
      pos now = q.front();
      q.pop();
      int x = now.x, y = now.y;

      for (int i=0; i<4; i++)
      {
        int nx = x +dx[i];
        int ny = y +dy[i];

        if (nx <0 || ny <0 || nx>=n || ny >= m) continue;
        if (visit[nx][ny]) continue;

        if (map[nx][ny]!='*' && !visit[nx][ny])
        {
          visit[nx][ny]=1;
          int state=0;

          if ( map[nx][ny] == '$') // 만약 돈을 먹었다면
          {
            ans++;
            state=1;
          }
          else if ('A'<= map[nx][ny] && map[nx][ny] <='Z' )
          { // 만약 문에 도달했다면
            if ( !keychk[map[nx][ny]-'A'] )
            { // 키가 없다면
              door[map[nx][ny]-'A'].push_back({nx, ny});
            }
            else state=1; // 키가 있다면
          }
          else if ('a' <= map[nx][ny] && map[nx][ny] <= 'z')
          { // 키를 얻었다면
            state=1;
            if ( !keychk[map[nx][ny]-'a'] ) //이전에는 키가 없었다면
            {
              keychk[map[nx][ny]-'a']=1;
              for (int i =0; i<door[map[nx][ny]-'a'].size(); i++)
              {
                q.push(door[map[nx][ny]-'a'][i]);
              }
              door[map[nx][ny]-'a'].clear();
            }

          }
          else if ( map[nx][ny] == '.') state=1;

          if (state)
          {
            q.push({nx, ny});
          }
        }
      }
    }
    printf("%d\n", ans);
  }
}
