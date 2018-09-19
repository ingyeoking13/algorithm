#include <stdio.h>
#include <deque>

using namespace std;

deque <int> dq;
char v[1000];
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    int now =n;
    for (int i=1; i<=n; i++) dq.push_back(i);
    printf("<");
    while(!dq.empty())
    {
        int tmp=0;
        for (int i=0; i<m; i++)
        {
            int now = dq.front();
            dq.pop_front();
            dq.push_back(now);
        }
        if (dq.size() >1)
        {
            printf("%d, ", dq.back());
            dq.pop_back();
        }
        else
        {
            printf("%d>\n", dq.back());
            dq.pop_back();
        }
    }
}