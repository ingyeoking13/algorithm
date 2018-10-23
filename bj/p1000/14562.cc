#include <stdio.h>
#include <queue>

using namespace std;
struct state
{
    int S, T, d;
    state(int S, int T, int d ) : S(S), T(T), d(d){}
};

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        queue<state> q;
        q.push( {n, m, 0});
        int ans=0;
        while(!q.empty())
        {
            auto now = q.front();
            q.pop();
            int tmpS = now.S, tmpT = now.T;
            if ( tmpS == tmpT) 
            {
                ans = now.d;
                break;
            }
            if (tmpS>tmpT) continue;
            q.push({tmpS+1,tmpT, now.d+1});
            q.push({tmpS*2, tmpT+3, now.d+1});
        }
        while(!q.empty()) q.pop();
        printf("%d\n", ans);
    }
}