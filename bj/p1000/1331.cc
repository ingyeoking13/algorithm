#include <stdio.h>

bool visit[26][26];
char abs(char x) { return x>0?x:-x; }

int main()
{
  char s[5];
  scanf("%s", s);
  char bcol = s[0]-'A';
  char brow = s[1]-'0';
  visit[bcol][brow]=1;

  for (int i=1; i<36; i++)
  {
    scanf("%s", s);
    char col = s[0]-'A';
    char row = s[1]-'0';

    if(visit[row][col])
    {
      return !printf("Invalid\n");
    }
    else if (abs(bcol-col)*abs(brow-row)!=2)
    {
      return !printf("Invalid\n");
    }

    visit[row][col]=1;

    bcol= col;
    brow =row;
  }

  printf("Valid\n");

}

