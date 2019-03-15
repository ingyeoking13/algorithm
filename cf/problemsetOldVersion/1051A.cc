#include <stdio.h>
#include <string.h>

char str[105];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", str);
        int len = strlen(str);

        int cap=0, sma=0, dig=0;
        for (int i=0; i<len; i++)
        {
            if ('A'<=str[i]  && str[i] <= 'Z') cap++;
            else if ('a' <= str[i] && str[i] <='z') sma++;
            else dig++;
        }

        if (dig >0 && cap >0 && sma > 0);
        else
        {
            if (dig == 0 && sma == 0)
            {
                str[0] ='1', str[1]='a';
            }
            else if (dig ==0 && cap == 0)
            {
                str[0]='1', str[1] = 'A';
            }
            else if (cap == 0 && sma == 0)
            {
                str[0]='A', str[1]='a';
            }
            else if ( cap==0)
            {
                if ( sma >1)
                {
                    for (int i=0; i<len; i++)
                    {
                        if ('a' <= str[i] && str[i] <='z')
                        {
                            str[i]='A';
                            break;
                        }
                    }
                }
                else if (dig >1)
                {
                    for (int i=0; i<len; i++)
                    {
                        if ('0' <= str[i] && str[i] <='9')
                        {
                            str[i]='A';
                            break;
                        }
                    }

                }

            }
            else if (sma==0)
            {
                if ( cap >1)
                {
                    for (int i=0; i<len; i++)
                    {
                        if ('A' <= str[i] && str[i] <='Z')
                        {
                            str[i]='a';
                            break;
                        }
                    }
                }
                else if (dig >1)
                {
                    for (int i=0; i<len; i++)
                    {
                        if ('0' <= str[i] && str[i] <='9')
                        {
                            str[i]='a';
                            break;
                        }
                    }

                }

            }
            else if (dig == 0)
            {
                if ( cap >1)
                {
                    for (int i=0; i<len; i++)
                    {
                        if ('A' <= str[i] && str[i] <='Z')
                        {
                            str[i]='0';
                            break;
                        }
                    }
                }
                else if (sma >1)
                {
                    for (int i=0; i<len; i++)
                    {
                        if ('a' <= str[i] && str[i] <='z')
                        {
                            str[i]='0';
                            break;
                        }
                    }

                }
            }
        }
        printf("%s\n", str);
    }


}
