#include <stdio.h>
#include <queue>

using namespace std;
queue<pair<int, int>> q;

char v[3*(1<<10)][3*(1<<10)*2];
char a[3*(1<<10)][3*(1<<10)*2];

void myPrint(int x, int y) // draw 1 triangle
{
    for (int i=0; i<=2; i++) a[x+i][y-i]= '*';// 7clock
    for (int i=0; i<=2; i++) a[x+i][y+i]= '*';// 5clock
    for (int i=-2; i<=2; i++) a[x+2][y+i]='*';// bottom
}

pair<int, int> l_c(int x, int y) //leftchild
{ return {x+3, y-3}; }
pair<int, int> r_c(int x, int y) //rightchild
{ return {x+3, y+3}; }

int main()
{
    int n; 
    scanf("%d", &n); // n will be height
    for (int i=0; i<n; i++)
        for (int j=0; j<2*n-1; j++)
            a[i][j]=' ';

    q.push({0, n-1});

    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        if ( now.first >=n ) break;

        int x = now.first, y = now.second;
        if (v[x][y]>=2)  continue;

        myPrint(x, y);

        pair<int, int> tmp = l_c(x, y);
        if (tmp.first<n)
        {
            v[tmp.first][tmp.second]++;
            q.push(tmp);

            tmp = r_c(x, y);
            v[tmp.first][tmp.second]++;
            q.push(r_c(x, y));
        }
    }
    for (int i=0; i<n; i++) printf("%s\n", a[i]);
}