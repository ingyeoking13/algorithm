#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<pair<long long, int> > pq;

int main( )
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        pq.push({-tmp, tmp});
    }

    long long ans=0;
    while(m)
    {
        auto now = pq.top();
        pq.pop();
        now.first = -now.first;
        ans = now.first;
        now.first +=  now.second;
        now.first = -now.first;
        pq.push(now);
        m--;
    }
    printf("%lld\n", ans);
}