#include <stdio.h>
#include <set>

using namespace std;
set<pair<int, int>> s;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {

        int m, n, x, y;
        scanf("%d%d%d%d", &m, &n, &x, &y);
        int a=0, b=0;
        x--, y--;
        if (a==x && b == y) 
        {
            printf("1\n");
            continue;
        }

        int ans=x+1;
        a=x, b=x;
        b%=n;
        s.insert({a, b});
        while(1)
        {
            if ( a== x && b == y) 
            {
                printf("%d\n", ans);
                break;
            }
            a+= m, b+= m;
            a%=m, b%=n;
            if (s.find({a, b})!=s.end())
            {
                ans=0;
                break;
            }
            ans+=m;
        }
        s.clear();
        if(!ans) printf("%d\n", -1);
    }
}