#include <stdio.h>
#include <string.h>

char s1[151], s2[151], s3[301];
typedef struct {
  int x, y; 
  int myans[300];
}state; 

int main()
{
  scanf("%s%s%s", s1, s2, s3);
  state Q[300]; 
  int h=0, t=0;
  Q[t].x=0;
  Q[t++].y=0;

  int n=strlen(s1); 
  int l=strlen(s2); 
  int r=strlen(s3);
  int v[300][300];

  while(h<t)
  {
    state now = Q[h++];

    if ( now.x+now.y == r)
    {
      for (int i=0; i<r; i++)
      {
        printf("%d", now.myans[i]);
      }
      printf("\n");
      return 0;
    }

    if ((!v[now.x][now.y]) && now.x <n && s1[now.x] == s3[now.x+now.y])
    {
      Q[t].x = now.x+1;
      Q[t].y = now.y;
      for (int i=0; i<now.x+now.y; i++)
      {
        Q[t].myans[i] = now.myans[i];
      }
      Q[t].myans[now.x+now.y]=1;
      v[now.x][now.y]=1;
      t++;
    }
    if ((!v[now.x][now.y]) && now.y <l && s2[now.y] == s3[now.x+now.y])
    {
      Q[t].x = now.x;
      Q[t].y = now.y+1;
      for (int i=0; i<now.x+now.y; i++)
      {
        Q[t].myans[i] = now.myans[i];
      }
      Q[t].myans[now.x+now.y]=2;
      v[now.x][now.y]=1;
      t++;
    }
  }
}
