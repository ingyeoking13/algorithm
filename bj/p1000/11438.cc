#include <stdio.h>
#include <vector>
using namespace std;

vector<int> e[1e5+1];
int p[1e5+1][17], d[50001];
int log2n;

void go(int now, int prev, int depth)
{
    if(p[now] != 0) return;
    p[now][0]=prev;
    for (int i=1; (1<<i)<=depth; i++) p[now][i] = p[p[now][i-1]][i-1];
    d[now]=depth;
    for (auto i : e[now]) go(i, now, depth+1);
}

int main()
{
    int n;
    scanf("%d", &n);

    //retrieve " floor ( log2(n) )"
    for (log2n=1; (1<<(log2n+1)) <= n; log2n++); 

    for (int i=0; i<n-1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    go(1, 0, 0);
    int m;
    scanf("%d", &m);
    while(m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);

        int dist = d[u]-d[v];

        if (dist>0) 
        {
            for (int i=0; i<dist; i++) u= p[u];
        }
        else for (int i=0; i<-dist; i++) v = p[v];
        while(u!=v) {
            u=p[u], v= p[v]; 
        }
        printf("%d\n", u);
    }
}