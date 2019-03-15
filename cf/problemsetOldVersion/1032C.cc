#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

char d[(int)1e5][6];
int a[(int)1e5];
char pred[(int)1e5][6];
stack<int> s;
int main()
{
  int n; scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", &a[i]);

  for (int i=1; i<=5; i++) d[0][i]=1;

  for (int i=1; i<n; i++)
  { 
    for (int j=1; j<=5; j++)
    {
      if ( a[i] > a[i-1] && d[i-1][j]==1)
      {
        for (int k=j+1; k<=5; k++) d[i][k]=1, pred[i][k]=j; 
      }
      else if ( a[i] < a[i-1] && d[i-1][j]==1)
      {
        for (int k=j-1; k>=1; k--) d[i][k]=1, pred[i][k]=j;
      }
      else if ( a[i] == a[i-1] && d[i-1][j]==1)
      {
        for (int k=j+1; k<=5; k++) d[i][k]=1, pred[i][k]=j; 
        for (int k=j-1; k>=1; k--) d[i][k]=1, pred[i][k]=j;
      }
    }
  }

  for (int i=1; i<=5; i++)
  {
    if (d[n-1][i])
    {
      int finger = i;
      s.push(finger);

      for (int j=n-1; j>0; j--)
      {
        finger = pred[j][finger];
        s.push(finger);
      }

      while(!s.empty())
      {
        int tt = s.top();
        s.pop();
        printf("%d ", tt);
      }
      printf("\n");
      return 0;
    }
  }

  printf("-1\n");

}
