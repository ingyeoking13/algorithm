#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
map<string, vector<string>> mm;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
   
    while(n--)
    {
        char s[102];
        scanf("%s",s);
        string twice = string(s);

        int T; scanf("%d", &T);
        while(T--)
        {
            char a[102]; scanf("%s", a);
            string mem = string(a);
            mm[twice].push_back(mem);
        }
    }

    while(m--)
    {
        char mem[102]; scanf("%s", mem);
        int d; scanf("%d", &d);
        if (d)
        {
            for (auto i: mm)
            {
                bool k=0;
                for (auto v: i.second)
                {
                    if ( v.compare(mem)==0) 
                    {
                        printf("%s\n", i.first.c_str());
                        k=1;
                        break;
                    }
                }
                if (k) break;
            }
        }
        else
        {
            for (auto i: mm)
            {
                if (i.first.compare(string(mem))==0)
                {
                    sort(i.second.begin(), i.second.end());
                    for (auto v : i.second)
                    {
                        printf("%s\n", v.c_str());
                    }
                    break;
                }
            }
        }
    }
}