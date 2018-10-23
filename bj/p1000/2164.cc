#include <stdio.h>
#include <deque>
using namespace std;

int main()
{
    deque<int> v;
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) 
        v.push_back(i);
    while(v.size()>1)
    {
        int tmp = v.front();
        v.pop_front();
        tmp = v.front();
        v.pop_front();
        v.push_back(tmp);
    }
    printf("%d\n", v[0]);
}