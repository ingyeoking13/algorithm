#include <stdio.h>
#include <stack>

using namespace std;

char ttuck[(int)1e3][10];
int ans[(int)1e3][10];

int main()
{
  int day;
  scanf("%d", &day);

  for (int i=0; i<day; i++)
  {
    int m;
    scanf("%d", &m);

    for (int j=0; j<m; j++) 
    {
      int kind;
      scanf("%d", &kind);
      ttuck[i][kind]=1;
    }
  }

  for (int i=1; i<=9; i++) if ( ttuck[0][i] ) ans[0][i]=1;

  for (int i=1; i<day; i++)
  {
    int prev_day = i-1;

    for (int j=1; j<=9; j++) // today TTuck
    {
      if ( ttuck[i][j] == 0) continue; // today TTuck non exist

      for (int k=1; k<=9; k++) // prev TTuck
      {
        if ( j== k) continue;
        if ( ttuck[prev_day][k] == 0) continue; // prev TTuck non exist
        if ( ans[prev_day][k] == 0) continue; // prev TTuck has non ans exist

        ans[i][j] = k;
      }
    }
  }

  int curday = day-1;
  bool chk=0;
  stack<int> s;
  for (int i=1; i<=9; i++)
  {
    if (ans[curday][i]) // exist
    {
      chk=1;
      s.push(i);
      while( curday >0 )
      {
        int prev_ttuck = ans[curday][i];
        s.push(prev_ttuck);
        curday--;
        i=prev_ttuck;
      }
      break;
    }
  }
  if ( !chk ) printf("-1\n");
  else 
  {
    while(!s.empty() )
    {
      printf("%d\n",s.top());
      s.pop();
    }
  }
}
