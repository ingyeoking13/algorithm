#include <stdio.h>
#include <queue>
#include <string.h>

#define REM 144000
using namespace std;

int ret(char* s)
{
  int r=0;
  for (int i=0; s[i]; i++)
  {
    if (s[i] == '\n') continue;
    if (s[i] == '.') continue;
    r *=10;
    r +=(s[i]-'0');
  }
  return r;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    char aa[10], bb[10], stst[10], targett[10];
    scanf("%s %s %s %s", aa, bb, stst, targett);

    int a = ret(aa);
    int b = ret(bb);
    int t= ret(targett);

    int st = (stst[0]=='A'?a:b);

    int visit[2005]; 
    memset(visit, -1, sizeof(visit));

    queue<int> q;
    q.push(st);
    visit[st-REM] = 0;

    while(!q.empty())
    {
      int now = q.front();
      q.pop();

      if (visit[a-REM] <0) visit[a-REM] = visit[now-REM]+1, q.push(a);
      if (visit[b-REM] <0) visit[b-REM] = visit[now-REM]+1, q.push(b);

      int uppress = now+20;
      if (uppress > 146000 ) uppress = 144000;
      if (visit[uppress-REM] <0) visit[uppress-REM] = visit[now-REM]+1, q.push(uppress);
    }

    int sta = visit[t-REM];
    memset(visit, -1, sizeof(visit));

    visit[st-REM] =0;
    q.push(st);
    while(!q.empty())
    {
      int now = q.front();
      q.pop();

      if (visit[a-REM] <0) visit[a-REM] = visit[now-REM]+1, q.push(a);
      if (visit[b-REM] <0) visit[b-REM] = visit[now-REM]+1, q.push(b);

      int downpress = now-20;
      if (downpress < 144000) downpress =146000;
      if (visit[downpress-REM] <0) visit[downpress-REM] = visit[now-REM]+1, q.push(downpress);
    }

    int stb = visit[t-REM];
    int ans=(stb<0?6:stb);
    if (sta >=0 && sta < ans)  ans = sta;

    printf("%d\n", ans);
  }
}
