#include <stdio.h>
#include <string.h>

char s[103];
const char* pattern[10] = {
  "0001101", "0011001", "0010011", "0111101",
  "0100011", "0110001", "0101111", "0111011",
  "0110111", "0001011"
};

int main()
{
  int T;
  scanf("%d", &T);
  for (int test_case=1; test_case <= T; test_case ++ )
  {
    int row, col;
    scanf("%d%d", &row, &col);
    memset(s, 0, sizeof(s));

    bool chk =false;
    for (int i=0; i<row; i++)
    {
      char tmp[103];
      scanf("%s", tmp);

      if (chk) continue;

      for (int j =0; j<col; j++)
      {
        if ( tmp[j] == '1' ) 
        {
          chk =true;
        }
      }

      if (chk) 
      {
        for (int j=0; j<col; j++)
        {
          s[j] = tmp[j];
        }
      }
    }

    int last =-1;
    for (int i=0; i<col; i++) if ( s[i] == '1') last = i;

    int start = last -7*8+ 1;
    int ans[7];

    for (int i=0; i<8; i++)
    {
      char cur[8];
      for (int j=0; j<7; j++)
      {
        cur[j] = s[ start + i*7 + j ];
      }

      for (int j=0; j<10; j++)
      {
        if ( strcmp(pattern[j], cur ) == 0 )
        {
          ans[i] = j;
          break;
        }
      }
    }
    int val = ( ans[0]+ans[2]+ans[4]+ans[6] )*3 + ( ans[1]+ans[3] + ans[5] );
    val += ans[7];
    if ( val % 10 == 0) 
    {
      int p=0;
      for (int i=0; i<8; i++)  p += ans[i];
      printf("#%d %d\n", test_case, p);
    }
    else printf("#%d 0\n", test_case);

  }
}
