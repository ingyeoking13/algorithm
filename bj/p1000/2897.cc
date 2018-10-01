#include <stdio.h>

char s[50][51];
int ans[5];
int main()
{
    int row, col;
    scanf("%d%d",&row, &col);
    for (int i=0; i<row; i++) scanf("%s", s[i]);

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if ( i+1 < row && j+1<col) // if access possible
            {
                int cnt=0, chk=1;
                for (int k=0; k<2; k++)
                {
                    for (int l=0; l<2; l++)
                    {
                        if ( s[i+k][j+l]=='#') 
                        {
                            chk=0;
                            break;
                        }
                        
                        if (s[i+k][j+l]=='X') cnt++;
                    }
                }

                if (chk) ans[cnt]++;
            }
        }
    }
    for (int i=0; i<5; i++) printf("%d\n", ans[i]);
}