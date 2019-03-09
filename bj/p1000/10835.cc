#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int d[2000][2000], a[2000], b[2000];
int n;

int go (int i,int j)
{
  if ( j==n || i == n) return 0;
  if ( d[i][j] != -1 )  return d[i][j];

  d[i][j]=0;

  int score=0;
  if ( a[i] > b[j] ) 
  {
    score = go(i, j+1) + b[j];
  }

  int mx = score;
  score = max(go(i+1, j+1), go(i+1, j));
  return d[i][j] = max(mx, score);
}

int main()
{
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  for (int i=0; i<n; i++) scanf("%d", &b[i]);

  memset(d, -1, sizeof(d));
  printf("%d\n" ,go(0, 0));
}
