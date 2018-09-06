#include <stdio.h>
#include <string.h>

char s[1501];
int d[1500][1500];
char need[3]= {'B', 'L', 'D'};

int go(int f, int t, char st)
{

  if (f>t) return 0; 

  if (d[f][t] >= 0) return d[f][t];

  d[f][t]=0;

  if (need[st] == s[f] )
  {
    d[f][t] = go (f+1, t, (st+1)%3)+1;
  }

  if (need[st] == s[t] )
  {
    int tmp = go (f, t-1, (st+1)%3)+1;
    if (tmp > d[f][t] ) d[f][t]=tmp;
  }

  return d[f][t];

}

int main()
{
  int n; scanf("%d", &n);
  scanf("%s", s);
  memset(d, -1, sizeof(d));

  printf("%d\n", go(0, 3*n - 1, 0));
}
