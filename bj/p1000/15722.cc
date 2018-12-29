#include <stdio.h>


int main()
{
  int n;
  scanf("%d", &n);

  int x=0, y=0;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  int status=0;
  int len=1;
  int cnt=0;
  int ccnt=0;

  for (int i=0; i<n; i++)
  {
    x += dx[status%4];
    y += dy[status%4];

    cnt++;
    if (len == cnt) 
    {
      ccnt++;
      if (ccnt==2) 
      {
        ccnt=0, len++;
      }
      cnt=0;
      status++;
    }
  }

  printf("%d %d\n", x, y);
}
