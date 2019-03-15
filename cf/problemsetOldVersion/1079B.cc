#include <stdio.h>
#include <string>

using namespace std;
char s[103];
int rowstrek[20];
int diff(int a, int b) { return b-a;};

int main()
{
  scanf("%s", s);
  string str(s);

  int len = str.size();
  int desired_col = len<=20?len:20;

  int row = len/desired_col;
  int rem= len%desired_col;

  while( rem!=0 && diff(rem,desired_col) !=0)
  {
    if (rem== desired_col-1) 
    {
      rowstrek[row]++;
      rem++;
      break;
    }

    if ( diff(rem+row, desired_col-1) <= -1 ) 
    {
      int strek = diff(rem, desired_col);
      for (int i=0; i<strek; i++) rowstrek[i]++;
      break;
    }

    desired_col--;
    rem+=(row);
  }

  printf("%d %d\n", row+(rem?1:0), desired_col);
  int idx=0;
  for (int i=0; i<row+ (rem?1:0); i++)
  {
    for (int j=0; j<desired_col-rowstrek[i]; j++)
    {
      printf("%c", s[idx++]);
    }
    for (int j=0; j<rowstrek[i]; j++) printf("*");
    printf("\n");
  }
  return 0;

}
